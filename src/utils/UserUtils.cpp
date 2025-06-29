#include "UserUtils.h"
#include "ConsoleUtils.h"
#include "Validador.h"
#include "../core/User.h"
#include "../core/Student.h"
#include "../core/Teacher.h"
#include <iostream>
#include <fstream>

using namespace std;

void saveStudent(const Student& student) {
    std::ofstream file("data/students.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo data/students.txt!" << std::endl;
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
    std::ofstream file("data/teachers.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo data/teachers.txt!" << std::endl;
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

        if (validateEmail(email, userType)) {
            emailIsValid = true;
        } else {
            setColor("red");
            cout << "E-mail inválido para " << (userType == "student" ? "aluno" : "professor") << ". Tente novamente.\n";
            resetColor();
        }

        // Aqui futuramente fará verificação se já existe cadastrado (em students.txt ou teachers.txt)
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
