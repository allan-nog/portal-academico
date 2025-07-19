#pragma once
#include <string>

/**
 * @brief Valida nomes completos.
 * 
 * Regras atuais:
 * - Deve conter pelo menos duas palavras separadas por espaço;
 * - Cada palavra deve conter apenas letras (acentos permitidos).
 * 
 * @param name Nome completo a ser validado.
 * @return true se válido, false caso contrário.
 */
bool validateName(const std::string& name);

/**
 * @brief Valida e-mails institucionais conforme o tipo de usuário.
 * 
 * Tipos suportados:
 * - "student" → e-mail deve ser @aluno.algumacoisa.br
 * - "teacher" → e-mail deve ser @algumacoisa.br
 * 
 * @param email E-mail a ser validado.
 * @param userType "student" ou "teacher".
 * @return true se válido, false caso contrário.
 */
bool validateEmail(const std::string& email, const std::string& userType);

/**
 * @brief Valida a senha com critérios mínimos.
 * 
 * Regras atuais:
 * - Mínimo de 6 caracteres.
 * 
 * @param password Senha a ser validada.
 * @return true se válida, false caso contrário.
 */
bool validatePassword(const std::string& password);
