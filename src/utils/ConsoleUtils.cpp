#include "ConsoleUtils.h"
#include <iostream>
#include <algorithm>

#ifdef _WIN32
    #include <windows.h> // Biblioteca especifica do Windows para manipulacao de console
#endif

// Altera a cor do texto do console para a cor especificada.
// Suporta "vermelho", "green", "azul", em inglês ou português.
// Qualquer outro valor reseta a cor
void setColor(const std::string &colorName){
    std::string color = colorName;
    std::transform(color.begin(), color.end(), color.begin(), ::tolower);
    #ifdef _WIN32
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        if (color == "red" || color == "vermelho") SetConsoleTextAttribute(console, 12);
        else if (color == "green" || color == "verde") SetConsoleTextAttribute(console, 10);
        else if (color == "azul" || color == "blue") SetConsoleTextAttribute(console, 9);
        else SetConsoleTextAttribute(console, 7);
    #else
        if (color == "red" || color == "vermelho") std::cout << "\033[1;31m";
        else if (color == "green" || color == "verde") std::cout << "\033[1;32m";
        else if (color == "azul" || color == "blue") std::cout << "\033[1;34m";
        else std::cout << "\033[0m";
    #endif
}

// Reseta a cor do texto para o padrão do console.
void resetColor(){
    setColor("");
}

// Limpa o console conforme o sistema operacional.
void limparConsole() {
    #ifdef _WIN32
        system("cls");  // Limpa o console no Windows
    #else
        system("clear"); // Limpa o console em sistemas Unix-like (Linux, macOS)
    #endif
}