#pragma once
#include <string>

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
void setColor(const std::string &colorName);

/**
 * @brief Reseta a cor do texto para o padrão do console.
 */
void resetColor();

/**
 * @brief Limpa o console, independente do sistema operacional.
 * 
 * Usa "cls" no Windows e "clear" no Linux/macOS.
 */
void limparConsole();
