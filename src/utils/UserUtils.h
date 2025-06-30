#pragma once
#include <string>
#include "../core/User.h"
#include "../core/Student.h"
#include "../core/Teacher.h"


/**
 * @brief Gera um hash seguro (Argon2id) para a senha informada.
 * 
 * Utiliza libsodium para gerar o hash, que já inclui salt e parâmetros embutidos
 * no formato $argon2id$v=19$m=...$.
 * 
 * @param password Senha pura digitada pelo usuário.
 * @return String contendo o hash completo. 
 * Retorna "" em caso de erro (por exemplo, falta de memória).
 */
std::string hashPassword(const std::string& password);


/**
 * @brief Verifica se uma senha pura corresponde ao hash armazenado.
 * 
 * Usa libsodium para comparar a senha informada com o hash Argon2id.
 * 
 * @param password Senha pura digitada pelo usuário no login.
 * @param hashedPassword Hash salvo no banco de dados / arquivo.
 * @return true se a senha está correta, false caso contrário.
 */
bool verifyPassword(const std::string& password, const std::string& hashedPassword);


/**
 * @brief Salva um estudante no arquivo de dados.
 * 
 * Grava os dados do estudante em data/students.txt no formato:
 * nome;email;hash_senha;matrícula;curso;período
 * 
 * @param student Instância do Student a ser salva.
 */
void saveStudent(const Student& student);


/**
 * @brief Salva um professor no arquivo de dados.
 * 
 * Grava os dados do professor em data/teachers.txt no formato:
 * nome;email;hash_senha;siape
 * 
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
 * Valida nome, e-mail e senha. Gera a instância Student ou Teacher, 
 * cria o hash seguro da senha e salva no arquivo.
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
 * Recebe e-mail e senha pelo terminal e verifica contra o hash salvo.
 * Se login for bem-sucedido, preenche userOut com os dados do usuário autenticado.
 * 
 * @param userType Tipo do usuário ("student" ou "teacher").
 * @param userOut Objeto User que receberá os dados do usuário autenticado.
 * @return 
 *  0 se login realizado com sucesso, 
 * -1 se usuário não encontrado, 
 * -2 se senha incorreta ou tentativas excedidas.
 */
int loginUser(const std::string& userType, User& userOut);
