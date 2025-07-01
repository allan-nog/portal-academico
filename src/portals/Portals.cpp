#include <iostream>
#include "../utils/ConsoleUtils.h"
#include "../utils/UserUtils.h"
#include "../core/User.h"
#include "Portals.h"
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
        studentOption = safeReadInt("Selecione uma opção: ");
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
                        loggedOption = safeReadInt("Selecione uma opção: ");
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
                                cout << "Senha: [oculta]\n"; // apenas para testes
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
                                cout << "\nOpcao invalida.\n";
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
        teacherOption = safeReadInt("Selecione uma opção: ");
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
                        loggedOption = safeReadInt("Selecione uma opção: ");
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
                                cout << "\nOpcao invalida.\n";
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
        adminOption = safeReadInt("Selecione uma opção: ");
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
                        adminLoggedOption = safeReadInt("Selecione uma opção: ");
                        clearConsole();

                        if (adminLoggedOption == 0) {
                            setColor("blue");
                            cout << "Logout efetuado.\n";
                            resetColor();
                            break;
                        }

                        switch (adminLoggedOption) {
                            case 1:
                                registerUser("student");
                                break;
                            case 2:
                                registerUser("teacher");
                                break;
                            case 3: {
                                setColor("blue");
                                cout << "Você quer atualizar:\n";
                                cout << "[1] - Aluno\n";
                                cout << "[2] - Professor\n";
                                resetColor();
                                int updateOption = safeReadInt("Escolha uma opção: ");

                                string email;
                                if (updateOption == 1) {
                                    cout << "Digite o e-mail atual do aluno: ";
                                    getline(cin, email);
                                    updateUser("student", email);
                                } else if (updateOption == 2) {
                                    cout << "Digite o e-mail atual do professor: ";
                                    getline(cin, email);
                                    updateUser("teacher", email);
                                } else {
                                    setColor("red");
                                    cout << "Opção inválida.\n";
                                    resetColor();
                                }
                                break;
                            }
                            case 4: {
                                setColor("blue");
                                cout << "Você quer visualizar:\n";
                                resetColor();
                                cout << "[1] - Alunos\n";
                                cout << "[2] - Professores\n";
                                setColor("blue");
                                cout<< "---------------------\n";
                                resetColor();
                                int viewOption = safeReadInt("Escolha uma opção: ");
                                clearConsole();

                                if (viewOption == 1) {
                                    listUsers("student");
                                } else if (viewOption == 2) {
                                    listUsers("teacher");
                                } else {
                                    setColor("red");
                                    cout << "Opção inválida.\n";
                                    resetColor();
                                }
                                break;
                            }
                            case 5: {
                                setColor("blue");
                                cout << "Você quer remover:\n";
                                resetColor();
                                cout << "[1] - Alunos\n";
                                cout << "[2] - Professores\n";
                                setColor("blue");
                                cout<< "---------------------\n";
                                resetColor();
                                int removeOption = safeReadInt("Escolha uma opção: ");

                                string email;
                                if (removeOption == 1) {
                                    cout << "\nDigite o e-mail do aluno a ser removido: ";
                                    getline(cin, email);
                                    removeUser("student", email);
                                } else if (removeOption == 2) {
                                    cout << "\nDigite o e-mail do professor a ser removido: ";
                                    getline(cin, email);
                                    removeUser("teacher", email);
                                } else {
                                    setColor("red");
                                    cout << "Opção inválida.\n";
                                    resetColor();
                                }
                                break;
                            }
                            case 6:
                                setColor("red");
                                cout << "Funcionalidade ainda não implementada.\n";
                                resetColor();
                                break;
                            default:
                                setColor("red");
                                cout << "\nOpcao invalida.\n";
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