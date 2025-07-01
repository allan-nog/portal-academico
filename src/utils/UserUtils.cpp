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
void ensureFileExists(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        // Não existe, vamos criar
        std::ofstream createFile(path);
        if (!createFile) {
            std::cerr << "Não foi possível criar o arquivo " << path << std::endl;
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

void listUsers(const std::string& userType) {
    std::string filePath;
    if (userType == "student") filePath = "data/students.txt";
    else if (userType == "teacher") filePath = "data/teachers.txt";
    else {
        setColor("red");
        std::cerr << "Tipo de usuário inválido!\n";
        resetColor();
        return;
    }

    std::ifstream inFile(filePath);
    if (!inFile) {
        setColor("red");
        std::cerr << "Erro ao abrir o arquivo: " << filePath << "\n";
        resetColor();
        return;
    }

    std::string line;
    bool hasUsers = false;
    while (getline(inFile, line)) {
        hasUsers = true;
        std::istringstream ss(line);
        std::string name, email, password;

        getline(ss, name, ';');
        getline(ss, email, ';');
        getline(ss, password, ';');

        setColor("yellow");
        std::cout << "Nome: " << name << "\n";
        std::cout << "Email: " << email << "\n";
        std::cout << "Senha: " << password << " (hash ou texto)\n";
        std::cout << "-------------------------------------\n";
        resetColor();
    }

    if (!hasUsers) {
        setColor("red");
        std::cout << "Nenhum usuário encontrado.\n";
        resetColor();
    }
}

bool removeUser(const std::string& userType, const std::string& email) {
    std::string filePath;
    if (userType == "student") filePath = "data/students.txt";
    else if (userType == "teacher") filePath = "data/teachers.txt";
    else {
        setColor("red");
        std::cerr << "Tipo de usuário inválido!\n";
        resetColor();
        return false;
    }

    std::ifstream inFile(filePath);
    if (!inFile) {
        setColor("red");
        std::cerr << "Erro ao abrir o arquivo: " << filePath << "\n";
        resetColor();
        return false;
    }

    std::ostringstream tempContent;
    std::string line;
    bool found = false;

    while (getline(inFile, line)) {
        std::istringstream ss(line);
        std::string name, storedEmail;
        getline(ss, name, ';');
        getline(ss, storedEmail, ';');

        if (storedEmail == email) {
            found = true; // não copia esta linha
        } else {
            tempContent << line << "\n";
        }
    }
    inFile.close();

    if (found) {
        std::ofstream outFile(filePath);
        outFile << tempContent.str();
        outFile.close();
        setColor("green");
        std::cout << "Usuário removido com sucesso!\n";
        resetColor();
    } else {
        setColor("red");
        std::cout << "Usuário com e-mail " << email << " não encontrado.\n";
        resetColor();
    }

    return found;
}

bool updateUser(const std::string& userType, const std::string& currentEmail) {
    std::string filePath;
    if (userType == "student") filePath = "data/students.txt";
    else if (userType == "teacher") filePath = "data/teachers.txt";
    else {
        setColor("red");
        std::cerr << "Tipo de usuário inválido!\n";
        resetColor();
        return false;
    }

    std::ifstream inFile(filePath);
    if (!inFile) {
        setColor("red");
        std::cerr << "Erro ao abrir o arquivo: " << filePath << "\n";
        resetColor();
        return false;
    }

    std::ostringstream tempContent;
    std::string line;
    bool found = false;

    while (getline(inFile, line)) {
        std::istringstream ss(line);
        std::string name, email, password, rest;

        getline(ss, name, ';');
        getline(ss, email, ';');
        getline(ss, password, ';');
        getline(ss, rest); // resto da linha

        if (email == currentEmail) {
            found = true;

            std::string newName, newEmail, newPassword;
            cout << "Novo nome (atual: " << name << "): ";
            getline(cin, newName);
            cout << "Novo email (atual: " << email << "): ";
            getline(cin, newEmail);
            cout << "Nova senha: ";
            getline(cin, newPassword);

            // reusa o hash!
            std::string hashedPassword = hashPassword(newPassword);

            tempContent << newName << ";" << newEmail << ";" << hashedPassword;
            if (!rest.empty()) tempContent << ";" << rest;
            tempContent << "\n";

            setColor("green");
            cout << "Usuário atualizado com sucesso!\n";
            resetColor();
        } else {
            tempContent << line << "\n";
        }
    }
    inFile.close();

    if (found) {
        std::ofstream outFile(filePath);
        outFile << tempContent.str();
        outFile.close();
    } else {
        setColor("red");
        cout << "Usuário com e-mail " << currentEmail << " não encontrado.\n";
        resetColor();
    }

    return found;
}
