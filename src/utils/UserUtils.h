#pragma once
#include <string>

/**
 * @brief Função responsável por registrar um usuário no sistema.
 * 
 * Faz a coleta do nome, email e senha, validando cada entrada.
 * Posteriormente poderá salvar o usuário em arquivo e garantir
 * unicidade do email.
 * 
 * @param userType Tipo do usuário ("student", "teacher", "admin").
 * @return int
 * -  0: sucesso
 * - -1: senha inválida
 * - -2: nome inválido
 * - -3: senhas não coincidem
 */
int registerUser(const std::string &userType);