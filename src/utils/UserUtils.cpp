#include "UserUtils.h"
#include "ConsoleUtils.h"
#include "Validador.h"
#include "../core/User.h"
#include "../core/Student.h"
#include "../core/Teacher.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <sodium.h> // Inclua o cabeçalho do libsodium
using namespace std;

// Função para gerar o hash seguro da senha (contém salt e parâmetros embutidos)        
string hashPassword(const string& password) {
    char hashed_password[crypto_pwhash_STRBYTES]; // Tamanho do buffer para o hash

    // Gere o hash da senha usando Argon2id
    if (crypto_pwhash_str(hashed_password,
                           password.c_str(),
                           password.length(),
                           crypto_pwhash_OPSLIMIT_MODERATE, // Nível de operações (custo computacional)
                           crypto_pwhash_MEMLIMIT_MODERATE) != 0) { // Limite de memória
        cerr << "Erro ao gerar hash. Memória insuficiente?" << endl; // Erro ao gerar o hash
        return "";
    }
    return hashed_password;
}

// Função para verificar a senha
bool verifyPassword(const string& password, const string& hashedPassword) {
    // Verifica a senha contra o hash armazenado
    if (crypto_pwhash_str_verify(hashedPassword.c_str(),
                                 password.c_str(),
                                 password.length()) != 0) {
        return false; // Senha incorreta
    }
    return true; // Senha correta
}

// Função para garantir que o arquivo sempre exista
void ensureFileExists(const string& path) {
    ifstream file(path);
    if (!file) {
        // Não existe, vamos criar
        ofstream createFile(path);
        if (!createFile) {
            cerr << "Não foi possível criar o arquivo " << path << endl;
        } else {
            createFile.close();
        }
    }
}

// Salva Student
void saveStudent(const Student& student) {
    ensureFileExists("data/students.txt");

    ofstream file("data/students.txt", ios::app);
    if (!file) {
        cerr << "Erro ao abrir o arquivo data/students.txt!" << endl;
        return;
    }
    file << student.getName() << ";"
         << student.getEmail() << ";"
         << student.getPassword() << ";"
         << student.getRegistration() << ";"
         << student.getCourse() << ";"
         << student.getPeriod() << "\n";

    clearConsole();
    setColor("green");
    cout << "\nAluno salvo com sucesso!" << endl;
    resetColor();
}

// Salva Teacher
void saveTeacher(const Teacher& teacher) {
    ensureFileExists("data/teachers.txt");
    ofstream file("data/teachers.txt", ios::app);
    if (!file) {
        cerr << "Erro ao abrir o arquivo data/teachers.txt!" << endl;
        return;
    }
    file << teacher.getName() << ";"
         << teacher.getEmail() << ";"
         << teacher.getPassword() << ";"
         << teacher.getSiape() << "\n";

    clearConsole();
    setColor("green");
    cout << "\nProfessor salvo com sucesso!" << endl;
    resetColor();
}

// Carrega um usuário pelo email, opcionalmente retorna o User
bool loadUser(const string& email, const string& userType, User* userOut) {
    string filePath;

    if (userType == "student") filePath = "data/students.txt";
    else if (userType == "teacher") filePath = "data/teachers.txt";
    else {
        setColor("red");
        cerr << "Tipo de usuário inválido!\n";
        resetColor();
        return false;
    }

    ensureFileExists(filePath);

    ifstream inFile(filePath);
    if (!inFile) {
        setColor("red");
        cerr << "Erro ao abrir o arquivo: " << filePath << "\n";
        resetColor();
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream ss(line);
        string name, storedEmail, password;
        
        getline(ss, name, ';');
        getline(ss, storedEmail, ';');
        getline(ss, password, ';');

        if (storedEmail == email) {
            if (userOut != nullptr) {
                *userOut = User(name, storedEmail, password);
            }
            return true;
        }
    }

    return false; // Não encontrado
}

// Função principal para registro de usuário
int registerUser(const string &userType) {

    // Garante o arquivo
    if (userType == "student") {
        ensureFileExists("data/students.txt");
    } else if (userType == "teacher") {
        ensureFileExists("data/teachers.txt");
    }

    string name, email, passwordEntered, confirmationPasswordEntered;
    bool nameIsValid = false, emailIsValid = false, passwordIsValid = false;

    setColor("blue");
    cout << "\n-------------- CADASTRO NO SISTEMA --------------\n";
    resetColor();

    // Nome
    while (!nameIsValid) {
        cout << "Nome completo: "; 
        getline(cin, name);

        if (!validateName(name)) {
            setColor("red");
            cout << "Nome inválido. Tente novamente.\n";
            resetColor();
        } else nameIsValid = true;
    }

    // Email
    while (!emailIsValid) {
        cout << "Digite o e-mail: ";
        getline(cin, email);

        if (!validateEmail(email, userType)) {
            setColor("red");
            cout << "E-mail inválido para " << (userType == "student" ? "aluno" : "professor") << ". Tente novamente.\n";
            resetColor();
        } else if (loadUser(email, userType)) {
            setColor("red");
            cout << "E-mail já cadastrado! Tente outro.\n";
            resetColor();
        } else emailIsValid = true;
    }

    // Senha
    while (!passwordIsValid) {
        cout << "Digite a senha: ";
        getline(cin, passwordEntered);
        if (!validatePassword(passwordEntered)) {
            setColor("red");
            cout << "Senha não atende aos requisitos.\n";
            resetColor();
            continue;
        }

        cout << "Confirme a senha: ";
        getline(cin, confirmationPasswordEntered);
        if (passwordEntered != confirmationPasswordEntered) {
            setColor("red");
            cout << "As senhas não coincidem.\n";
            resetColor();
        } else passwordIsValid = true;
    }
    
    string hashedPassword = hashPassword(passwordEntered);

    // Salva no arquivo adequado
    if (userType == "student") {
        Student student(name, email, hashedPassword, 12345, "<desconhecido>", 0);
        saveStudent(student);
    } else if (userType == "teacher") {
        Teacher teacher(name, email, hashedPassword, 0);
        saveTeacher(teacher);
    }

    return 0;
}

int loginUser(const string& userType, User& userOut) {

    string email, password;
    int attempts = 5;

    setColor("blue");
    cout << "\n--------------- ENTRE NO SISTEMA ---------------\n";
    resetColor();

    cout << "Digite o e-mail: ";
    getline(cin, email);

    if (!loadUser(email, userType, &userOut)) {
        setColor("red");
        cout << "Usuário não encontrado ou erro ao carregar dados.\n";
        resetColor();
        return -1;
    }

    while (attempts > 0) {
        cout << "Digite a senha: ";
        getline(cin, password);

        if (verifyPassword(password, userOut.getPassword())) {
            clearConsole();
            setColor("green");
            cout << "\nLogin realizado com sucesso!\n";
            resetColor();
            return 0;
        } else {
            attempts--;
            setColor("red");
            if (attempts > 0) {
                cout << "Senha incorreta. Tentativas restantes: " << attempts << "\n";
            } else {
                clearConsole();
                cout << "Número máximo de tentativas excedido. Tente novamente mais tarde.\n";
            }
            resetColor();
        }
    }

    return -2; // Login bloqueado por excesso de tentativas

}

void listUsers(const string& userType) {
    string filePath;
    if (userType == "student") filePath = "data/students.txt";
    else if (userType == "teacher") filePath = "data/teachers.txt";
    else {
        setColor("red");
        cerr << "Tipo de usuário inválido!\n";
        resetColor();
        return;
    }

    ifstream inFile(filePath);
    if (!inFile) {
        setColor("red");
        cerr << "Erro ao abrir o arquivo: " << filePath << "\n";
        resetColor();
        return;
    }

    string line;
    bool hasUsers = false;
    while (getline(inFile, line)) {
        hasUsers = true;
        istringstream ss(line);
        string name, email, password;

        getline(ss, name, ';');
        getline(ss, email, ';');
        getline(ss, password, ';');

        setColor("yellow");
        cout << "Nome: " << name << "\n";
        cout << "Email: " << email << "\n";
        cout << "Senha: " << password << " (hash ou texto)\n";
        cout << "-------------------------------------\n";
        resetColor();
    }

    if (!hasUsers) {
        setColor("red");
        cout << "Nenhum usuário encontrado.\n";
        resetColor();
    }
}

bool removeUser(const string& userType, const string& email) {
    string filePath;
    if (userType == "student") filePath = "data/students.txt";
    else if (userType == "teacher") filePath = "data/teachers.txt";
    else {
        setColor("red");
        cerr << "Tipo de usuário inválido!\n";
        resetColor();
        return false;
    }

    ifstream inFile(filePath);
    if (!inFile) {
        setColor("red");
        cerr << "Erro ao abrir o arquivo: " << filePath << "\n";
        resetColor();
        return false;
    }

    ostringstream tempContent;
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        istringstream ss(line);
        string name, storedEmail;
        getline(ss, name, ';');
        getline(ss, storedEmail, ';');

        if (storedEmail == email) {
            found = true;
            setColor("yellow");
            cout << "\nUsuário encontrado: " << name << " <" << storedEmail << ">\n";
            resetColor();

            string confirm;
            cout << "Tem certeza que deseja remover? (s/n): ";
            getline(cin, confirm);

            if (confirm != "s" && confirm != "S") {
                setColor("red");
                cout << "Operação cancelada pelo usuário.\n";
                resetColor();
                tempContent << line << "\n"; // mantém o usuário
            } else {
                setColor("green");
                cout << "Usuário removido com sucesso.\n";
                resetColor();
                // não adiciona ao tempContent, efetivamente removendo
            }
        } else {
            tempContent << line << "\n";
        }
    }
    inFile.close();

    if (found) {
        ofstream outFile(filePath);
        outFile << tempContent.str();
        outFile.close();
    } else {
        setColor("red");
        cout << "Usuário com e-mail " << email << " não encontrado.\n";
        resetColor();
    }

    return found;
}

bool updateUser(const string& userType, const string& currentEmail) {
    string filePath;
    if (userType == "student") filePath = "data/students.txt";
    else if (userType == "teacher") filePath = "data/teachers.txt";
    else {
        setColor("red");
        cerr << "Tipo de usuário inválido!\n";
        resetColor();
        return false;
    }

    ifstream inFile(filePath);
    if (!inFile) {
        setColor("red");
        cerr << "Erro ao abrir o arquivo: " << filePath << "\n";
        resetColor();
        return false;
    }

    ostringstream tempContent;
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        istringstream ss(line);
        string name, email, password, rest;

        getline(ss, name, ';');
        getline(ss, email, ';');
        getline(ss, password, ';');
        getline(ss, rest);

        if (email == currentEmail) {
            found = true;
            string newName, newEmail, newPassword;

            // Nome
            do {
                cout << "Novo nome (atual: " << name << ", ENTER para manter): ";
                getline(cin, newName);
                if (newName.empty()) newName = name;
                if (!validateName(newName)) {
                    setColor("red");
                    cout << "Nome inválido. Tente novamente.\n";
                    resetColor();
                } else break;
            } while (true);

            // Email
            do {
                cout << "Novo email (atual: " << email << ", ENTER para manter): ";
                getline(cin, newEmail);
                if (newEmail.empty()) newEmail = email;
                if (!validateEmail(newEmail, userType)) {
                    setColor("red");
                    cout << "Email inválido.\n";
                    resetColor();
                } else if (newEmail != currentEmail && loadUser(newEmail, userType)) {
                    setColor("red");
                    cout << "Email já cadastrado para outro usuário.\n";
                    resetColor();
                } else break;
            } while (true);

            // Senha
            do {
                cout << "Nova senha (deixe vazio para manter a atual): ";
                getline(cin, newPassword);
                if (newPassword.empty()) {
                    newPassword = password; // já está hash
                    break;
                }
                if (!validatePassword(newPassword)) {
                    setColor("red");
                    cout << "Senha não atende aos requisitos.\n";
                    resetColor();
                } else {
                    newPassword = hashPassword(newPassword);
                    break;
                }
            } while (true);

            // Reescreve a linha
            tempContent << newName << ";" << newEmail << ";" << newPassword;
            if (!rest.empty()) tempContent << ";" << rest;
            tempContent << "\n";

            setColor("green");
            cout << "✅ Usuário atualizado com sucesso!\n";
            resetColor();
        } else {
            tempContent << line << "\n";
        }
    }
    inFile.close();

    if (found) {
        ofstream outFile(filePath);
        if (!outFile) {
            setColor("red");
            cout << "Erro ao salvar o arquivo atualizado.\n";
            resetColor();
            return false;
        }
        outFile << tempContent.str();
        outFile.close();
    } else {
        setColor("red");
        cout << "Usuário não encontrado.\n";
        resetColor();
    }

    return found;
}

void createRequest(const string& studentEmail) {
    string message;
    setColor("blue");
    cout << "\n------ NOVO REQUERIMENTO ------\n";
    resetColor();
    cout << "Digite seu requerimento: ";
    getline(cin, message);

    // Pega timestamp
    time_t now = time(nullptr);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Garante arquivo existe
    ofstream file("data/requests.txt", ios::app);
    if (!file) {
        setColor("red");
        cerr << "Erro ao abrir o arquivo data/requests.txt\n";
        resetColor();
        return;
    }

    file << studentEmail << ";" << message << ";" << buf << "\n";
    file.close();

    setColor("green");
    cout << "Requerimento registrado com sucesso!\n";
    resetColor();
}

void listRequests() {
    std::ifstream file("data/requests.txt");
    if (!file) {
        setColor("red");
        std::cerr << "Nenhum requerimento encontrado ou erro ao abrir o arquivo.\n";
        resetColor();
        return;
    }

    std::string line;
    bool hasRequests = false;
    while (getline(file, line)) {
        hasRequests = true;
        std::istringstream ss(line);
        std::string email, message, timestamp;

        getline(ss, email, ';');
        getline(ss, message, ';');
        getline(ss, timestamp, ';');

        setColor("yellow");
        std::cout << "Email: " << email << "\n";
        std::cout << "Requerimento: " << message << "\n";
        std::cout << "Data/Hora: " << timestamp << "\n";
        std::cout << "------------------------------------\n";
        resetColor();
    }

    if (!hasRequests) {
        setColor("red");
        std::cout << "Nenhum requerimento registrado ainda.\n";
        resetColor();
    }
}

