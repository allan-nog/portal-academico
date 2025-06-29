#include <iostream>
#include "utils/ConsoleUtils.h"
#include "utils/UserUtils.h"
using namespace std;

void studentPortal(){
    int studentOption;
    while (true) {
        setColor("azul");
        cout << "\n--------- PORTAL DO ALUNO ----------\n";
        resetColor();
        cout << "[1] - Registrar novo aluno\n";
        cout << "[2] - Login\n";
        cout << "[0] - Voltar ao menu principal\n" ;
        setColor("azul");
        cout << "------------------------------------\n";
        resetColor();
        cout << "Selecione uma opcao: ";
        setColor("verde");
        cin >> studentOption;
        cin.ignore();
        resetColor();
        limparConsole();
        if (studentOption == 0){
            break;
        }
        switch (studentOption) {
            case 1:
                registerUser("student");
                break;
            case 2:
                cout << "FUNÇÃO DE LOGAR\n";
                break;
            default:
                setColor("vermelho");
                cout << "\nOpcao invalida.\n";
                resetColor();
                break;
        }
    }
}

void teacherPortal(){
    int teacherOption;
    while (true) {
        setColor("azul");
        cout << "\n-------- PORTAL DO PROFESSOR ---------\n";
        resetColor();
        cout << "[1] - Login\n";
        cout << "[0] - Voltar ao menu principal\n" ;
        setColor("azul");
        cout << "--------------------------------------\n";
        resetColor();
        cout << "Selecione uma opcao: ";
        setColor("verde");
        cin >> teacherOption;
        cin.ignore();
        resetColor();
        limparConsole();
        if (teacherOption == 0){
            break;
        }
        switch (teacherOption) {
            case 1:
                cout << "FUNÇÃO DE LOGAR\n";
                break;
            default:
                setColor("vermelho");
                cout << "\nOpcao invalida.\n";
                resetColor();
                break;
        }
    }
}

void adminPortal(){
    int adminOption;
    while (true) {
        setColor("azul");
        cout << "\n------ PORTAL DO ADMINISTRADOR -------\n";
        resetColor();
        cout << "[1] - Login\n";
        cout << "[0] - Voltar ao menu principal\n" ;
        setColor("azul");
        cout << "--------------------------------------\n";
        resetColor();
        cout << "Selecione uma opcao: ";
        setColor("verde");
        cin >> adminOption;
        cin.ignore();
        resetColor();
        limparConsole();
        if (adminOption == 0){
            break;
        }
        switch (adminOption) {
            case 1:
                cout << "FUNÇÃO DE LOGAR\n";
                break;
            default:
                setColor("vermelho");
                cout << "\nOpcao invalida.\n";
                resetColor();
                break;
        }
    }
}

int main(){

    int option;
    while (true){
        setColor("azul");
        cout << "\n---------- MENU DO SISTEMA ----------\n";
        resetColor();
        cout << "[1] - Portal do Aluno\n";
        cout << "[2] - Portal do Professor\n";
        cout << "[3] - Portal do Administrador\n" ;
        cout << "[0] - Sair\n";
        setColor("azul");
        cout << "-------------------------------------\n";
        resetColor();
        cout << "Selecione uma opcao: ";
        setColor("verde");
        cin >> option;
        cin.ignore();
        resetColor();
        limparConsole();
        if (option == 0){
            setColor("azul");
            cout << "\n-------- PROGRAMA ENCERRADO ---------\n";
            resetColor();
            break;
        }
        switch (option) {
            case 1:
                studentPortal();
                break;
            case 2:
                teacherPortal();
                break;
            case 3:
                adminPortal();
                break;
            default:
                setColor("vermelho");
                cout << "\nOpcao invalida.\n";
                resetColor();
                break;
        }
    }

    return 0;

}