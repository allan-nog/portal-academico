#include "UserUtils.h"
#include "ConsoleUtils.h"
#include "Validador.h"
#include "../core/User.h"
#include <iostream>

using namespace std;

int registerUser(const string &userType) {
    string name, email, passwordEntered, confirmationPasswordEntered;
    bool nameIsValid = false, emailIsValid = false, isRegistered = false;

    setColor("blue");
    cout << "\n-------- CADASTRO NO SISTEMA --------\n";
    resetColor();

    while (!nameIsValid) {
        cout << "Digite seu nome: "; 
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

        if (validateEmail(email)) {
            emailIsValid = true;
        } else {
            setColor("red");
            cout << "E-mail inválido para " << (userType == "student" ? "aluno" : "professor") << ". Tente novamente.\n";
            resetColor();
        }

        // Aqui futuramente fará verificação se já existe cadastrado (em students.txt ou teachers.txt)
    }

    cout << "Digite sua senha: ";
    getline(cin, passwordEntered);
    if (!validatePassword(passwordEntered)) {
        setColor("red");
        cout << "Senha não atende aos requisitos.\n";
        resetColor();
        return -1;
    }

    cout << "Confirme sua senha: ";
    getline(cin, confirmationPasswordEntered);
    if (!validatePassword(confirmationPasswordEntered)) {
        setColor("red");
        cout << "Senha de confirmação não atende aos requisitos.\n";
        resetColor();
        return -1;
    }

    if (passwordEntered != confirmationPasswordEntered) {
        setColor("red");
        cout << "As senhas não coincidem.\n";
        resetColor();
        return -3;
    }

    setColor("green");
    cout << "Usuário registrado com sucesso!\n";
    resetColor();

    // Aqui no futuro poderá salvar no arquivo correspondente
    // ex: saveUser(User(name, email, passwordEntered), userType);

    return 0;
}
