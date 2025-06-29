#include "UserUtils.h"
#include "ConsoleUtils.h"
#include "Validador.h"
#include "../core/User.h"
#include "../core/Student.h"
#include "../core/Teacher.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void saveStudent(const Student& student) {
    ofstream file("data/students.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo data/students.txt!" << endl;
        return;
    }
    file << student.getName() << ";"
         << student.getEmail() << ";"
         << student.getPassword() << ";"
         << student.getRegistration() << ";"
         << student.getCourse() << ";"
         << student.getPeriod() << "\n";
    file.close();
    setColor("green");
    cout << "\nAluno salvo com sucesso!" << endl;
    resetColor();
}

void saveTeacher(const Teacher& teacher) {
    ofstream file("data/teachers.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo data/teachers.txt!" << endl;
        return;
    }
    file << teacher.getName() << ";"
         << teacher.getEmail() << ";"
         << teacher.getPassword() << ";"
         << teacher.getSiape() << "\n";
    file.close();
    setColor("green");
    cout << "\nProfessor salvo com sucesso!" << endl;
    resetColor();
}

// Verifica se o usuário existe pelo email
bool userExists(const string& email, const string& userType) {
    string filePath;

    if (userType == "student") {
        filePath = "data/students.txt";
    } else if (userType == "teacher") {
        filePath = "data/teachers.txt";
    } else {
        setColor("red");
        cerr << "Tipo de usuário inválido!\n";
        resetColor();
        return false;
    }

    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        setColor("red");
        cerr << "Erro ao abrir o arquivo: " << filePath << "\n";
        resetColor();
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream ss(line);
        string name, storedEmail, password;
        
        // Para leitura de alunos ou professores, assume: name;email;password;...
        getline(ss, name, ';');
        getline(ss, storedEmail, ';');
        getline(ss, password, ';');

        if (storedEmail == email) {
            return true; // Usuário existe
        }
    }

    return false; // Não encontrado
}

int registerUser(const string &userType) {
    string name, email, passwordEntered, confirmationPasswordEntered;
    bool nameIsValid = false, emailIsValid = false, passwordIsValid = false, isRegistered = false;

    setColor("blue");
    cout << "\n-------- CADASTRO NO SISTEMA --------\n";
    resetColor();

    while (!nameIsValid) {
        cout << "Digite seu nome completo: "; 
        getline(cin, name);

        if (!validateName(name)) {
            setColor("red");
            cout << "Nome inválido. Tente novamente.\n";
            resetColor();
        } else
            nameIsValid = true;
    }

    while (!emailIsValid) {
        cout << "Digite seu e-mail: ";
        getline(cin, email);

        if (!validateEmail(email, userType)) {
            setColor("red");
            cout << "E-mail inválido para " << (userType == "student" ? "aluno" : "professor") << ". Tente novamente.\n";
            resetColor();
        } else if (userExists(email, userType)) {
            setColor("red");
            cout << "E-mail já cadastrado! Tente outro.\n";
            resetColor();
        } else {
            emailIsValid = true;
        }
    }

    while (!passwordIsValid) {
        cout << "Digite sua senha: ";
        getline(cin, passwordEntered);
        if (!validatePassword(passwordEntered)) {
            setColor("red");
            cout << "Senha não atende aos requisitos.\n";
            resetColor();
            continue;
        }

        cout << "Confirme sua senha: ";
        getline(cin, confirmationPasswordEntered);
        if (!validatePassword(confirmationPasswordEntered)) {
            setColor("red");
            cout << "Senha de confirmação não atende aos requisitos.\n";
            resetColor();
            continue;
        }

        if (passwordEntered != confirmationPasswordEntered) {
            setColor("red");
            cout << "As senhas não coincidem.\n";
            resetColor();
        } else {
            passwordIsValid = true;
        }
    }
    
    if (userType == "student") {
        Student student(name, email, passwordEntered, 12345, "<desconhecido>", 0);
        saveStudent(student);
    } else if (userType == "teacher") {
        Teacher teacher(name, email, passwordEntered, 0);
        saveTeacher(teacher);
    }

    return 0;
}
