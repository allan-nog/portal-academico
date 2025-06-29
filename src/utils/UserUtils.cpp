#include "UserUtils.h"
#include "ConsoleUtils.h"
#include "Validador.h"
#include "../core/User.h"
#include <iostream>

using namespace std;

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
    
    setColor("green");
    cout << "\nUsuário registrado com sucesso!\n";
    resetColor();

    // Aqui no futuro poderá salvar no arquivo correspondente
    // ex: saveUser(User(name, email, passwordEntered), userType);

    return 0;
}
