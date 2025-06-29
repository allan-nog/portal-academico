#pragma once
#include <string>
#include "../core/User.h"
#include "../core/Student.h"
#include "../core/Teacher.h"

/**
 * @brief Salva um estudante no arquivo de dados.
 * @param student Instância do Student a ser salva.
 */
void saveStudent(const Student& student);

/**
 * @brief Salva um professor no arquivo de dados.
 * @param teacher Instância do Teacher a ser salva.
 */
void saveTeacher(const Teacher& teacher);

/**
 * @brief Carrega um usuário do arquivo com base no e-mail.
 * 
 * Procura em data/students.txt ou data/teachers.txt dependendo do userType.
 * Se userOut não for nulo, preenche o objeto User com os dados carregados.
 * 
 * @param email Email do usuário a ser buscado.
 * @param userType Tipo do usuário ("student" ou "teacher").
 * @param userOut Ponteiro opcional para armazenar o usuário carregado.
 * @return true se o usuário foi encontrado, false caso contrário.
 */
bool loadUser(const std::string& email, const std::string& userType, User* userOut = nullptr);

/**
 * @brief Registra um novo usuário (student ou teacher) interativamente via terminal.
 * 
 * @param userType Tipo do usuário ("student" ou "teacher").
 * @return 
 *  0 se cadastro realizado,
 * -1 se erro genérico.
 */
int registerUser(const std::string &userType);

/**
 * @brief Função genérica para login de usuário (student ou teacher).
 * 
 * @param userType Tipo do usuário ("student" ou "teacher").
 * @param userOut Objeto User que receberá os dados do usuário autenticado.
 * @return 
 *  0 se login realizado com sucesso, 
 * -1 se usuário não encontrado, 
 * -2 se senha incorreta.
 */
int loginUser(const std::string& userType, User& userOut);