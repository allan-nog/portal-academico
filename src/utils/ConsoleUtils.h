#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <limits>

#ifdef _WIN32
    #include <windows.h> // Para manipulação de console no Windows
#endif

/**
 * @brief Altera a cor do texto do console para a cor especificada.
 *
 * Cores suportadas (case-insensitive):
 * - "vermelho" ou "red"
 * - "verde" ou "green"
 * - "azul" ou "blue"
 * - "amarelo" ou "yellow"
 * - "ciano" ou "cyan"
 * - "magenta" ou "purple"
 *
 * Qualquer outro valor reseta para o padrão.
 *
 * @param colorName Nome da cor.
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
 * @brief Limpa o console, independente do Sistema Operacional.
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
 * @brief Lê um número inteiro do usuário de forma segura, com cores e tratamento.
 * 
 * Mostra a mensagem na cor padrão, muda para verde para o input,
 * reseta depois, e faz flush do buffer.
 * 
 * @param message Mensagem a ser exibida antes da leitura.
 * @return O inteiro lido.
 */
inline int safeReadInt(const std::string& message) {
    int value;
    while (true) {
        std::cout << message;
        setColor("green");
        if (std::cin >> value) {
            resetColor();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            resetColor();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            setColor("red");
            std::cout << "Entrada inválida. Por favor, digite um número inteiro.\n";
            resetColor();
        }
    }
}