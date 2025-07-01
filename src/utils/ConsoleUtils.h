#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <limits>

#ifdef _WIN32
    #include <windows.h> // Biblioteca específica do Windows para manipulação de console
#endif


/**
 * @brief Altera a cor do texto do console para a cor especificada.
 *
 * Cores suportadas (case-insensitive):
 * - "vermelho" ou "red"
 * - "verde" ou "green"
 * - "azul" ou "blue"
 *
 * Qualquer outro valor reseta a cor para o padrão do console.
 *
 * @param colorName Nome da cor, em português ou inglês.
 */
inline void setColor(const std::string &colorName) {
    std::string color = colorName;
    std::transform(color.begin(), color.end(), color.begin(), ::tolower);
    #ifdef _WIN32
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        if (color == "red" || color == "vermelho") SetConsoleTextAttribute(console, 12);
        else if (color == "green" || color == "verde") SetConsoleTextAttribute(console, 10);
        else if (color == "azul" || color == "blue") SetConsoleTextAttribute(console, 9);
        else if (color == "amarelo" || color == "yellow") SetConsoleTextAttribute(console, 6);
        else if (color == "ciano" || color == "cyan") SetConsoleTextAttribute(console, 3);
        else if (color == "magenta" || color == "purple") SetConsoleTextAttribute(console, 5);
        else SetConsoleTextAttribute(console, 7);
    #else
        if (color == "red" || color == "vermelho") std::cout << "\033[1;31m";
        else if (color == "green" || color == "verde") std::cout << "\033[1;32m";
        else if (color == "azul" || color == "blue") std::cout << "\033[1;34m";
        else if (color == "amarelo" || color == "yellow") std::cout << "\033[1;33m";
        else if (color == "ciano" || color == "cyan") std::cout << "\033[1;36m";
        else if (color == "magenta" || color == "purple") std::cout << "\033[1;35m";
        else std::cout << "\033[0m";
    #endif
}


/**
 * @brief Reseta a cor do texto para o padrão do console.
 */
inline void resetColor() {
    setColor("");
}


/**
 * @brief Limpa o console, independente do sistema operacional.
 *
 * Usa "cls" no Windows e "clear" no Linux/macOS.
 */
inline void clearConsole() {
    std::cout << std::flush;
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


/**
 * @brief Lê um número inteiro do console de forma segura.
 * Exibe o prompt, verifica se o input é um inteiro. Se não for, pede novamente.
 *
 * @param prompt Texto a exibir antes de ler.
 * @return Um inteiro válido digitado pelo usuário.
 */
inline int safeReadInt(const std::string& prompt) {
    int value;
    while (true) {
        setColor("green");
        std::cout << prompt;
        resetColor();
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            setColor("red");
            std::cout << "Entrada inválida! Digite um número inteiro.\n";
            resetColor();
        }
    }
}
