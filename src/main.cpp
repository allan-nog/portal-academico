#include <iostream>
#include <ctime>
#include "portals/Portals.h"
#include "utils/ConsoleUtils.h"
#include "utils/Curriculum.h"
using namespace std;

int main() {
    // Inicializa gerador de números aleatórios (para matrículas/SIAPE)
    srand(static_cast<unsigned int>(time(nullptr)));

    // Carrega o currículo completo a partir do arquivo curriculum.txt
    vector<CurriculumItem> curriculum = loadCurriculum("data/curriculum.txt");

    if (curriculum.empty()) {
        setColor("red");
        cerr << "Erro: Nenhuma disciplina foi carregada do currículo. Verifique o arquivo data/curriculum.txt.\n";
        resetColor();
        return 1;
    }

    int option;
    while (true) {
        setColor("blue");
        cout << "\n---------- PORTAL ACADÊMICO ----------\n";
        resetColor();
        cout << "[1] - Portal do Aluno\n";
        cout << "[2] - Portal do Professor\n";
        cout << "[3] - Portal do Administrador\n";
        cout << "[0] - Sair\n";
        setColor("blue");
        cout << "--------------------------------------\n";
        resetColor();
        option = safeReadInt("Escolha uma opção: ");
        clearConsole();

        switch (option) {
            case 1:
                studentPortal(curriculum);
                break;
            case 2:
                teacherPortal(curriculum);
                break;
            case 3:
                adminPortal(curriculum);
                break;
            case 0:
                setColor("blue");
                cout << "\n--------- PROGRAMA ENCERRADO ---------\n";
                resetColor();
                return 0;
            default:
                setColor("red");
                cout << "\nOpção inválida. Tente novamente.\n";
                resetColor();
        }
    }

    return 0;
}

// Compilação:
// g++ src/main.cpp src/core/*.cpp src/utils/*.cpp src/portals/Portals.cpp -o programa -lsodium