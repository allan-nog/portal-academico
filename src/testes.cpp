#include <iostream>
#include <vector>
#include "utils/ConsoleUtils.h"
#include "aluno/Aluno.h"
#include "professor/Professor.h"
#include "usuario/Usuario.h"
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
        resetColor();
        limparConsole();
        if (studentOption == 0){
            break;
        }
        switch (studentOption) {
            case 1:
                cout << "FUNÇÃO DE CADASTRAR ALUNO\n";
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

    // Criar disciplinas
    Disciplina d1 {"Estruturas de Dados", 60};
    Disciplina d2 {"Banco de Dados", 40};
    Disciplina d3 {"Programação Orientada a Objetos", 80};
    Disciplina d4 {"Compiladores", 60};

    // Criar Aluno
    Aluno aluno1("Maria Silva", "maria@gmail.com", "12345", 2023101, "Ciência da Computação", 3);
    aluno1.addDisciplina(d1);
    aluno1.addDisciplina(d2);

    // Criar Professor
    Teacher prof1("Carlos Oliveira", "carlos@uni.edu", "admin", 4567);
    prof1.addDisciplina(d3);
    prof1.addDisciplina(d4);

    // Imprimir dados
    cout << "\n===== DADOS DO ALUNO =====\n";
    aluno1.printInfo();

    cout << "\n===== DADOS DO PROFESSOR =====\n";
    prof1.printInfo();

    // Testando polimorfismo
    cout << "\n===== TESTE COM VECTOR<User*> =====\n";
    vector<User*> usuarios;
    usuarios.push_back(&aluno1);
    usuarios.push_back(&prof1);

    for (auto u : usuarios) {
        u->printInfo();
        cout << "--------------------------\n";
    }

    return 0;

}