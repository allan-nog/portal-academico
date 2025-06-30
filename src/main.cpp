#include <iostream>
#include "utils/ConsoleUtils.h"
#include "utils/UserUtils.h"
using namespace std;

void studentPortal(){
    int studentOption;
    while (true) {
        setColor("blue");
        cout << "\n--------- PORTAL DO ALUNO ----------\n";
        resetColor();
        cout << "[1] - Registrar novo aluno\n";
        cout << "[2] - Login\n";
        cout << "[0] - Voltar ao menu principal\n";
        setColor("blue");
        cout << "------------------------------------\n";
        resetColor();
        cout << "Selecione uma opcao: ";
        setColor("green");
        cin >> studentOption;
        cin.ignore();
        resetColor();
        clearConsole();

        if (studentOption == 0) break;

        switch (studentOption) {
            case 1:
                registerUser("student");
                break;
            case 2: {
                User user;
                if (loginUser("student", user) == 0){
                    setColor("yellow");
                    cout << "\nBem vindo, " << user.getName() << "!\n";
                    resetColor();

                    int loggedOption;
                    while (true) {
                        setColor("blue");
                        cout << "\n----------- MENU DO ALUNO -----------\n";
                        resetColor();
                        cout << "[1] - Visualizar perfil\n";
                        cout << "[2] - Atualizar dados (futuro)\n";
                        cout << "[3] - Visualizar notas\n";
                        cout << "[4] - Visualizar frequência\n";
                        cout << "[5] - Registrar requerimento\n";
                        cout << "[0] - Logout\n";
                        setColor("blue");
                        cout << "-------------------------------------\n";
                        resetColor();
                        cout << "Selecione uma opcao: ";
                        setColor("green");
                        cin >> loggedOption;
                        cin.ignore();
                        resetColor();
                        clearConsole();

                        if (loggedOption == 0) {
                            setColor("blue");
                            cout << "Logout efetuado.\n";
                            resetColor();
                            break;
                        }

                        switch (loggedOption) {
                            case 1:
                                setColor("yellow");
                                cout << "---------- SEU PERFIL ----------\n";
                                cout << "Nome: " << user.getName() << "\n";
                                cout << "Email: " << user.getEmail() << "\n";
                                cout << "Senha: " << user.getPassword() << "\n"; // apenas para testes
                                resetColor();
                                break;
                            case 2:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            case 3:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            case 4:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            case 5:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            default:
                                setColor("red");
                                cout << "Opção inválida.\n";
                                resetColor();
                                break;
                        }
                    }
                }
                break;
            }
            default:
                setColor("red");
                cout << "\nOpcao invalida.\n";
                resetColor();
                break;
        }
    }
}

void teacherPortal(){
    int teacherOption;
    while (true) {
        setColor("blue");
        cout << "\n-------- PORTAL DO PROFESSOR ---------\n";
        resetColor();
        cout << "[1] - Login\n";
        cout << "[0] - Voltar ao menu principal\n";
        setColor("blue");
        cout << "--------------------------------------\n";
        resetColor();
        cout << "Selecione uma opcao: ";
        setColor("green");
        cin >> teacherOption;
        cin.ignore();
        resetColor();
        clearConsole();

        if (teacherOption == 0) break;

        switch (teacherOption) {
            case 1: {
                User user;
                if (loginUser("teacher", user) == 0){
                    setColor("yellow");
                    cout << "\nBem vindo, " << user.getName() << "!\n";
                    resetColor();

                    int loggedOption;
                    while (true) {
                        setColor("blue");
                        cout << "\n--------- MENU DO PROFESSOR ---------\n";
                        resetColor();
                        cout << "[1] - Visualizar perfil\n";
                        cout << "[2] - Atualizar dados (futuro)\n";
                        cout << "[3] - Registrar notas\n";
                        cout << "[4] - Registrar frequência\n";
                        cout << "[0] - Logout\n";
                        setColor("blue");
                        cout << "-------------------------------------\n";
                        resetColor();
                        cout << "Selecione uma opcao: ";
                        setColor("green");
                        cin >> loggedOption;
                        cin.ignore();
                        resetColor();
                        clearConsole();

                        if (loggedOption == 0) {
                            setColor("blue");
                            cout << "Logout efetuado.\n";
                            resetColor();
                            break;
                        }

                        switch (loggedOption) {
                            case 1:
                                setColor("yellow");
                                cout << "---------- SEU PERFIL ----------\n";
                                cout << "Nome: " << user.getName() << "\n";
                                cout << "Email: " << user.getEmail() << "\n";
                                cout << "Senha: " << user.getPassword() << "\n"; // apenas para testes
                                resetColor();
                                break;
                            case 2:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            case 3:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            case 4:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            default:
                                setColor("red");
                                cout << "Opção inválida.\n";
                                resetColor();
                                break;
                        }
                    }
                }
                break;
            }
            default:
                setColor("red");
                cout << "\nOpcao invalida.\n";
                resetColor();
                break;
        }
    }
}

void adminPortal(){
    const string adminEmail = "admin@admin.com";
    const string adminPassword = "admin123";
    string email, password;
    int attempts = 3, adminOption;
    while (true) {
        setColor("blue");
        cout << "\n------ PORTAL DO ADMINISTRADOR -------\n";
        resetColor();
        cout << "[1] - Login\n";
        cout << "[0] - Voltar ao menu principal\n";
        setColor("blue");
        cout << "--------------------------------------\n";
        resetColor();
        cout << "Selecione uma opcao: ";
        setColor("green");
        cin >> adminOption;
        cin.ignore();
        resetColor();
        clearConsole();

        if (adminOption == 0) break;

        switch (adminOption) {
            case 1: {
                bool logged = false;
                attempts = 3;
                while (attempts > 0) {
                    setColor("blue");
                    cout << "\n-------------- ENTRE NO SISTEMA --------------\n";
                    resetColor();

                    cout << "Digite o e-mail: ";
                    getline(cin, email);
                    cout << "Digite a senha: ";
                    getline(cin, password);

                    if (email == adminEmail && password == adminPassword) {
                        logged = true;
                        clearConsole();
                        setColor("green");
                        cout << "\nLogin de administrador realizado com sucesso!\n";
                        resetColor();
                        break;
                    } else {
                        attempts--;
                        setColor("red");
                        if (attempts > 0)
                            cout << "Email ou senha incorretos. Tentativas restantes: " << attempts << "\n";
                        else {
                            clearConsole();
                            cout << "Número máximo de tentativas excedido.\n";
                        }
                        resetColor();
                    }
                }

                if (logged) {
                    // Sub-menu do admin
                    int adminLoggedOption;
                    while (true) {
                        setColor("blue");
                        cout << "\n------- MENU DO ADMINISTRADOR -------\n";
                        resetColor();
                        cout << "[1] - Cadastrar aluno\n";
                        cout << "[2] - Cadastrar professor\n";
                        cout << "[3] - Atualizar dados (futuro)\n";
                        cout << "[4] - Visualizar usuários\n";
                        cout << "[5] - Remover usuário\n";
                        cout << "[6] - Visualizar requerimentos\n";
                        cout << "[0] - Logout\n";
                        setColor("blue");
                        cout << "--------------------------------------\n";
                        resetColor();
                        cout << "Selecione uma opcao: ";
                        setColor("green");
                        cin >> adminLoggedOption;
                        cin.ignore();
                        resetColor();
                        clearConsole();

                        if (adminLoggedOption == 0) {
                            setColor("blue");
                            cout << "Logout efetuado.\n";
                            resetColor();
                            break;
                        }

                        switch (adminLoggedOption) {
                            case 1:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            case 2:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            case 3:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            case 4:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            case 5:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            case 6:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            default:
                                setColor("red");
                                cout << "Opcao invalida.\n";
                                resetColor();
                                break;
                        }
                    }
                }
                break;
            }
            default:
                setColor("red");
                cout << "\nOpcao invalida.\n";
                resetColor();
                break;
        }
    }
}

int main(){
    int option;
    while (true){
        setColor("blue");
        cout << "\n---------- MENU DO SISTEMA ----------\n";
        resetColor();
        cout << "[1] - Portal do Aluno\n";
        cout << "[2] - Portal do Professor\n";
        cout << "[3] - Portal do Administrador\n";
        cout << "[0] - Sair\n";
        setColor("blue");
        cout << "-------------------------------------\n";
        resetColor();
        cout << "Selecione uma opcao: ";
        setColor("green");
        cin >> option;
        cin.ignore();
        resetColor();
        clearConsole();

        if (option == 0){
            setColor("blue");
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
                setColor("red");
                cout << "\nOpcao invalida.\n";
                resetColor();
                break;
        }
    }
    return 0;
}
