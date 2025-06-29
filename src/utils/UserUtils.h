#pragma once
#include <string>
#include "../core/Student.h"
#include "../core/Teacher.h"

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

/**
 * @brief Salva os dados de um estudante no arquivo correspondente.
 * 
 * @param student Objeto Student a ser salvo.
 */
void saveStudent(const Student& student);

/**
 * @brief Salva os dados de um professor no arquivo correspondente.
 * 
 * @param teacher Objeto Teacher a ser salvo.
 */
void saveTeacher(const Teacher& teacher);

/**
 * @brief Verifica se um usuário já existe no sistema com base no email e tipo.
 * 
 * @param email Email do usuário para verificação.
 * @param userType Tipo do usuário ("student", "teacher").
 * @return true Se o usuário já existir.
 * @return false Se o usuário não existir.
 */
bool userExists(const std::string& email, const std::string& userType);
