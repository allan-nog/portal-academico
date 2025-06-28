#pragma once
#include <iostream>
#include "ConsoleUtils.h"
#include "../core/User.h"
using namespace std;

void registerUser(){
    string name, email, password;
    setColor("blue");
    cout << "------ CADASTRO NO SISTEMA ----------\n" << endl;
    resetColor();

    cout << "Digite seu nome: ";
    cin.ignore(); 
    getline(cin, name);
    cout << "Nome registrado: " << name << endl;
}
