#include <iostream>
using namespace std;

void studentPortal(){
    int studentOption;
    while (true) {
        cout << "\n--------- PORTAL DO ALUNO ----------\n";
        cout << "[1] - Registrar novo aluno\n";
        cout << "[2] - Login\n";
        cout << "[0] - Voltar ao menu principal\n" ;
        cout << "------------------------------------\n";
        cout << "Selecione uma opcao: ";
        cin >> studentOption;
        if (studentOption == 0){
            cout << "\n---------- VOLTANDO AO MENU PRINCIPAL -----------\n";
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
                cout << "\nOpcao invalida.\n";
                break;
        }
    }
}

void teacherPortal(){
    int teacherOption;
    while (true) {
        cout << "\n-------- PORTAL DO PROFESSOR ---------\n";
        cout << "[1] - Login\n";
        cout << "[0] - Voltar ao menu principal\n" ;
        cout << "--------------------------------------\n";
        cout << "Selecione uma opcao: ";
        cin >> teacherOption;
        if (teacherOption == 0){
            cout << "\n---------- VOLTANDO AO MENU PRINCIPAL -----------\n";
            break;
        }
        switch (teacherOption) {
            case 1:
                cout << "FUNÇÃO DE LOGAR\n";
                break;
            default:
                cout << "\nOpcao invalida.\n";
                break;
        }
    }
}

void adminPortal(){
    int adminOption;
    while (true) {
        cout << "\n------ PORTAL DO ADMINISTRADOR -------\n";
        cout << "[1] - Login\n";
        cout << "[0] - Voltar ao menu principal\n" ;
        cout << "--------------------------------------\n";
        cout << "Selecione uma opcao: ";
        cin >> adminOption;
        if (adminOption == 0){
            cout << "\n---------- VOLTANDO AO MENU PRINCIPAL -----------\n";
            break;
        }
        switch (adminOption) {
            case 1:
                cout << "FUNÇÃO DE LOGAR\n";
                break;
            default:
                cout << "\nOpcao invalida.\n";
                break;
        }
    }
    cout << "\n\nFUNCIONALIDADES DO ADMINISTRADOR\n\n";
}

int main(){

    int option;
    while (true){
        cout << "\n---------- MENU DO SISTEMA ----------\n";
        cout << "[1] - Portal do Aluno\n";
        cout << "[2] - Portal do Professor\n";
        cout << "[3] - Portal do Administrador\n" ;
        cout << "[0] - Sair\n";
        cout << "-------------------------------------\n";
        cout << "Selecione uma opcao: ";
        cin >> option;
        if (option == 0){
            cout << "\n---------- PROGRAMA ENCERRADO -----------\n";
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
                cout << "\nOpcao invalida.\n";
                break;
        }
    }

    return 0;

}