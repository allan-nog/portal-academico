#include "UserUtils.h"
#include "ConsoleUtils.h"
#include "Validador.h"
#include "IdUtils.h"
#include "../core/User.h"
#include "../core/Student.h"
#include "../core/Teacher.h"
#include "../core/Request.h"
#include <iostream>
#include <fstream>
#include <iomanip>
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
    string name, email, passwordEntered, confirmationPasswordEntered;
    bool nameIsValid = false, emailIsValid = false, passwordIsValid = false;

    setColor("blue");
    cout << "\n------------- CADASTRO NO SISTEMA -------------\n";
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
        cout << "E-mail: ";
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
        cout << "Senha: ";
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

    // Salva no arquivo adequado
    if (userType == "student") {
        string course;
        cout << "Digite o curso: ";
        getline(cin, course);

        int period = safeReadInt("Digite o período atual: ");

        string registration = generateStudentRegistration(1); // código fixo do curso = 1

        Student student(name, email, hashPassword(passwordEntered), registration, course, period);
        saveStudent(student);

    } else if (userType == "teacher") {
        string siape = generateTeacherSiape();
        Teacher teacher(name, email, hashPassword(passwordEntered), siape);
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
        cout << "------------------------------------------------\n";
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
    cout << "\n-------------- NOVO REQUERIMENTO --------------\n";
    resetColor();
    cout << "Digite seu requerimento: ";
    getline(cin, message);

    time_t now = time(nullptr);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));

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
    ifstream inFile("data/requests.txt");
    if (!inFile) {
        setColor("red");
        cerr << "Erro ao abrir o arquivo data/requests.txt\n";
        resetColor();
        return;
    }

    string line;
    bool found = false;
    while (getline(inFile, line)) {
        istringstream ss(line);
        string email, desc, date;
        getline(ss, email, ';');
        getline(ss, desc, ';');
        getline(ss, date);

        Request req(email, desc, date);
        req.print();
        found = true;
    }

    if (!found) {
        setColor("red");
        cout << "Nenhum requerimento encontrado.\n";
        resetColor();
    }
}

void registerGrade(const string& teacherEmail) {
    while (true) {
        string studentEmail, discipline;
        double grade;

        setColor("blue");
        cout << "\n-------------- REGISTRO DE NOTAS --------------\n";
        resetColor();

        cout << "Email do aluno: ";
        getline(cin, studentEmail);

        // Confirma se o aluno existe
        if (!loadUser(studentEmail, "student")) {
            setColor("red");
            cout << "Aluno não encontrado. Não é possível lançar nota.\n";
            resetColor();
        } else {
            cout << "Disciplina: ";
            getline(cin, discipline);
            
            while (true) {
                cout << "Nota (0 a 100): ";
                setColor("green");
                if (cin >> grade && grade >= 0 && grade <= 100) {
                    resetColor();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                } else {
                    resetColor();
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    setColor("red");
                    cout << "Nota inválida. Digite um número entre 0 e 100.\n";
                    resetColor();
                }
            }

            // Padrão de status
            string status = (grade >= 60) ? "Aprovado" : "Reprovado";

            // Atualiza ou cria o registro
            ifstream inFile("data/enrollments.txt");
            ostringstream tempContent;
            bool found = false;
            string line;

            while (getline(inFile, line)) {
                istringstream ss(line);
                string emailFile, disciplineFile, rest;
                getline(ss, emailFile, ';');
                getline(ss, disciplineFile, ';');

                if (emailFile == studentEmail && disciplineFile == discipline) {
                    found = true;
                    tempContent << studentEmail << ";" << discipline << ";" << grade << ";" << status << "\n";
                } else {
                    tempContent << line << "\n";
                }
            }
            inFile.close();

            if (!found) {
                tempContent << studentEmail << ";" << discipline << ";" << grade << ";" << status << "\n";
            }

            ofstream outFile("data/enrollments.txt");
            outFile << tempContent.str();
            outFile.close();

            setColor("green");
            cout << "Nota registrada com sucesso!\n";
            resetColor();
        }

        // Pergunta se quer continuar
        string answer;
        cout << "Deseja lançar nota para outro aluno? (s/n): ";
        getline(cin, answer);
        if (answer != "s" && answer != "S") {
            break;
        }
        clearConsole();
    }
}


void registerAttendance(const string& teacherEmail) {
    string studentEmail, courseName, date, presence;

    setColor("blue");
    cout << "\n------------- REGISTRAR FREQUÊNCIA -------------\n";
    resetColor();

    // Email do aluno
    while (true) {
        cout << "Digite o e-mail do aluno: ";
        getline(cin, studentEmail);
        if (!validateEmail(studentEmail, "student")) {
            setColor("red");
            cout << "Email inválido para aluno. Tente novamente.\n";
            resetColor();
        } else {
            break;
        }
    }

    // Nome da disciplina
    cout << "Digite o nome da disciplina: ";
    getline(cin, courseName);

    // Data
    cout << "Digite a data (YYYY-MM-DD) ou pressione ENTER para hoje: ";
    getline(cin, date);
    if (date.empty()) {
        time_t now = time(nullptr);
        char buf[11];
        strftime(buf, sizeof(buf), "%Y-%m-%d", localtime(&now));
        date = buf;
    }

    // Presença ou falta
    while (true) {
        cout << "Presença (P) ou Falta (A): ";
        getline(cin, presence);
        if (presence == "P" || presence == "p" || presence == "A" || presence == "a") {
            presence[0] = toupper(presence[0]);
            break;
        } else {
            setColor("red");
            cout << "Digite apenas P ou A.\n";
            resetColor();
        }
    }

    // Grava em attendance.txt
    ofstream attFile("data/attendance.txt", ios::app);
    attFile << studentEmail << ";" << courseName << ";" << date << ";" << presence << "\n";
    attFile.close();

    // Agora recalcula % de presença
    ifstream inFile("data/attendance.txt");
    int total = 0, presentes = 0;
    string line;
    while (getline(inFile, line)) {
        istringstream ss(line);
        string fEmail, fCourse, fDate, fStatus;
        getline(ss, fEmail, ';');
        getline(ss, fCourse, ';');
        getline(ss, fDate, ';');
        getline(ss, fStatus, ';');

        if (fEmail == studentEmail && fCourse == courseName) {
            total++;
            if (fStatus == "P") presentes++;
        }
    }
    inFile.close();

    double percent = (total > 0) ? (presentes * 100.0 / total) : 0.0;

    // Atualiza enrollments.txt
    ifstream enrFile("data/enrollments.txt");
    ostringstream tempContent;
    bool found = false;
    while (getline(enrFile, line)) {
        istringstream ss(line);
        string eEmail, eCourse;
        double grade, attPercent;
        string status;

        getline(ss, eEmail, ';');
        getline(ss, eCourse, ';');
        ss >> grade;
        ss.ignore();
        ss >> attPercent;
        ss.ignore();
        getline(ss, status);

        if (eEmail == studentEmail && eCourse == courseName) {
            found = true;
            status = (grade >=6 && percent >=75) ? "Aprovado" : "Reprovado";
            tempContent << eEmail << ";" << eCourse << ";" << grade << ";" 
                        << fixed << setprecision(1) << percent << ";" << status << "\n";
        } else {
            tempContent << line << "\n";
        }
    }
    enrFile.close();

    if (!found) {
        string status = (percent >=75) ? "Aprovado" : "Reprovado";
        tempContent << studentEmail << ";" << courseName << ";0;" 
                    << fixed << setprecision(1) << percent << ";" << status << "\n";
    }

    ofstream outFile("data/enrollments.txt");
    outFile << tempContent.str();
    outFile.close();

    setColor("green");
    cout << "Frequência registrada e situação atualizada com sucesso!\n";
    resetColor();
}

void viewGrades(const string& studentEmail) {
    ifstream inFile("data/enrollments.txt");
    if (!inFile) {
        setColor("red");
        cout << "Nenhum dado de matrícula encontrado.\n";
        resetColor();
        return;
    }

    string line;
    bool found = false;

    setColor("blue");
    cout << "\n----------------- SUAS NOTAS ------------------\n";
    resetColor();

    cout << left << setw(25) << "Disciplina" 
              << setw(8) << "Nota" 
              << setw(12) << "Freq(%)" 
              << "Status\n";
    cout << "-----------------------------------------------\n";

    while (getline(inFile, line)) {
        istringstream ss(line);
        string email, course, status;
        double grade, attendance;

        getline(ss, email, ';');
        getline(ss, course, ';');
        ss >> grade;
        ss.ignore();
        ss >> attendance;
        ss.ignore();
        getline(ss, status);

        if (email == studentEmail) {
            found = true;
            cout << left << setw(25) << course
                      << setw(8) << fixed << setprecision(1) << grade
                      << setw(12) << attendance
                      << status << "\n";
        }
    }

    if (!found) {
        setColor("red");
        cout << "Nenhuma disciplina encontrada.\n";
        resetColor();
    }
}

void registerAttendance(const string& teacherEmail) {
    while (true) {
        string studentEmail, discipline, date;
        bool present;

        setColor("blue");
        cout << "\n------------ REGISTRO DE FREQUÊNCIA ------------\n";
        resetColor();

        cout << "Email do aluno: ";
        getline(cin, studentEmail);

        // Verifica se o aluno existe
        if (!loadUser(studentEmail, "student")) {
            setColor("red");
            cout << "Aluno não encontrado. Não é possível lançar frequência.\n";
            resetColor();
        } else {
            cout << "Disciplina: ";
            getline(cin, discipline);

            // Validação básica de data YYYY-MM-DD
            while (true) {
                cout << "Data (YYYY-MM-DD): ";
                getline(cin, date);

                if (date.size() == 10 && date[4] == '-' && date[7] == '-') {
                    break;
                } else {
                    setColor("red");
                    cout << "Formato de data inválido. Use YYYY-MM-DD.\n";
                    resetColor();
                }
            }

            string presenceInput;
            while (true) {
                cout << "Presença (s para presente, n para falta): ";
                getline(cin, presenceInput);
                if (presenceInput == "s" || presenceInput == "S") {
                    present = true;
                    break;
                } else if (presenceInput == "n" || presenceInput == "N") {
                    present = false;
                    break;
                } else {
                    setColor("red");
                    cout << "Opção inválida. Digite 's' ou 'n'.\n";
                    resetColor();
                }
            }

            // Atualiza arquivo de frequência
            ifstream inFile("data/enrollments.txt");
            ostringstream tempContent;
            bool found = false;
            string line;

            while (getline(inFile, line)) {
                istringstream ss(line);
                string emailFile, disciplineFile, gradeStr, status;
                getline(ss, emailFile, ';');
                getline(ss, disciplineFile, ';');
                getline(ss, gradeStr, ';');
                getline(ss, status, ';');

                if (emailFile == studentEmail && disciplineFile == discipline) {
                    found = true;
                    // Adiciona presença atual ao final da linha
                    tempContent << emailFile << ";" << disciplineFile << ";" << gradeStr << ";" << status
                                << ";" << date << ":" << (present ? "P" : "F") << "\n";
                } else {
                    tempContent << line << "\n";
                }
            }
            inFile.close();

            if (!found) {
                setColor("red");
                cout << "Aluno não possui registro de matrícula na disciplina. Cadastre primeiro a nota.\n";
                resetColor();
            } else {
                ofstream outFile("data/enrollments.txt");
                outFile << tempContent.str();
                outFile.close();

                setColor("green");
                cout << "Frequência registrada com sucesso!\n";
                resetColor();
            }
        }

        // Pergunta se quer continuar
        string answer;
        cout << "Deseja lançar frequência para outro aluno? (s/n): ";
        getline(cin, answer);
        if (answer != "s" && answer != "S") {
            break;
        }
        clearConsole();
    }
}




