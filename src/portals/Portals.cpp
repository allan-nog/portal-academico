#include <iostream>
#include "../utils/ConsoleUtils.h"
#include "../utils/UserUtils.h"
#include "../utils/Curriculum.h"
#include "../core/User.h"
#include "Portals.h"
using namespace std;

void studentPortal(const vector<CurriculumItem>& curriculum){
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
                        cout << "[2] - Atualizar dados\n";
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
                                cout << "Senha: [oculta]\n";
                                resetColor();
                                break;
                            case 2: {
                                setColor("yellow");
                                cout << "\nAtualizando dados para o usuário: " << user.getEmail() << endl;
                                resetColor();
                                updateUser("student", user.getEmail());
                                break;
                            }
                            case 3:
                                viewGrades(user.getEmail());
                                break;
                            case 4:
                                viewAttendance(user.getEmail());
                                break;
                            case 5:
                                createRequest(user.getEmail());
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
                cout << "Opção inválida.\n";
                resetColor();
                break;
        }
    }
}

void teacherPortal(const vector<CurriculumItem>& curriculum) {
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
                        cout << "[2] - Atualizar dados\n";
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
                                cout << "Senha: [oculta]\n"; 
                                resetColor();
                                break;
                            case 2: {
                                setColor("yellow");
                                cout << "\nAtualizando dados para o usuário: " << user.getEmail() << endl;
                                resetColor();
                                updateUser("teacher", user.getEmail());
                                break;
                            }
                            case 3:
                                registerGrade(user.getEmail(), curriculum);
                                break;
                            case 4:
                                registerAttendance(user.getEmail(), curriculum);
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
                cout << "Opção inválida.\n";
                resetColor();
                break;
        }
    }
}

void adminPortal(const vector<CurriculumItem>& curriculum){
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
                        cout << "[3] - Atualizar dados\n";
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
                                resetColor();
                                cout << "[1] - Alunos\n";
                                cout << "[2] - Professores\n";
                                setColor("blue");
                                cout<< "---------------------\n";
                                resetColor();
                                int updateOption = safeReadInt("Escolha uma opção: ");

                                string email;
                                if (updateOption == 1) {
                                    cout << "\nDigite o e-mail atual do aluno: ";
                                    getline(cin, email);
                                    updateUser("student", email);
                                } else if (updateOption == 2) {
                                    cout << "\nDigite o e-mail atual do professor: ";
                                    getline(cin, email);
                                    updateUser("student", email, true);  // Pula verificação de senha
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
                                listRequests();
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
                cout << "Opção inválida.\n";
                resetColor();
                break;
        }
    }
}