#include "portals/Portals.h"
#include "utils/ConsoleUtils.h"
#include <iostream>
using namespace std;

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
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
        option = safeReadInt("Escolha uma opção: ");
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

// Para compilar: g++ src/main.cpp src/core/*.cpp src/utils/*.cpp src/portals/Portals.cpp -o programa -lsodium