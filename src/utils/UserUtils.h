#pragma once
#include <string>
#include <vector>
#include "../core/User.h"
#include "../core/Student.h"
#include "../core/Teacher.h"
#include "Curriculum.h"


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
 * @brief Carrega um aluno pelo número de matrícula.
 * 
 * @param registration Matrícula do aluno a buscar.
 * @param userOut Ponteiro opcional para retornar dados básicos do User.
 * @return true se encontrado, false se não encontrado.
 */
bool loadStudentByRegistration(const std::string& registration, Student& studentOut);

/**
 * @brief Carrega um estudante do arquivo pelo email.
 * 
 * Preenche todos os dados do objeto Student.
 * 
 * @param email Email do aluno.
 * @param studentOut Ponteiro para receber o objeto Student carregado.
 * @return true se encontrou, false se não encontrou.
 */
bool loadStudentByEmail(const std::string& email, Student& studentOut);

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


/**
 * @brief Lista usuários cadastrados no sistema, podendo ser alunos ou professores.
 * 
 * @param userType "student" ou "teacher"
 */
void listUsers(const std::string& userType);


/**
 * @brief Remove um usuário (student ou teacher) com base no e-mail.
 * 
 * @param userType "student" ou "teacher"
 * @param email E-mail do usuário a ser removido
 * @return true se removido com sucesso, false caso não encontrado
 */
bool removeUser(const std::string& userType, const std::string& email);


/**
 * @brief Atualiza nome, email ou senha de um usuário com base no email atual.
 * 
 * @param userType "student" ou "teacher"
 * @param currentEmail Email atual para localizar o usuário
 * @return true se atualizado, false caso usuário não encontrado
 */
bool updateUser(const std::string& userType, const std::string& currentEmail);


/**
 * @brief Permite que um aluno registre um requerimento, que será salvo em arquivo.
 * 
 * @param studentEmail Email do aluno autenticado.
 */
void createRequest(const std::string& studentEmail);


/**
 * @brief Exibe todos os requerimentos registrados pelos alunos.
 */
void listRequests();


/**
 * @brief Permite o professor lançar ou atualizar notas do aluno em disciplinas obrigatórias.
 * 
 * Exige verificar currículo para validar a disciplina.
 * 
 * @param teacherEmail Email do professor logado.
 * @param curriculum Vetor do currículo carregado com as disciplinas.
 */
void registerGrade(const std::string& teacherEmail, const std::vector<CurriculumItem>& curriculum);

/**
 * @brief Permite o professor registrar frequência do aluno em disciplinas obrigatórias.
 * 
 * Exige verificar currículo para validar a disciplina.
 * 
 * @param teacherEmail Email do professor logado.
 * @param curriculum Vetor do currículo carregado com as disciplinas.
 */
void registerAttendance(const std::string& teacherEmail, const std::vector<CurriculumItem>& curriculum);

/**
 * @brief Permite ao aluno visualizar suas notas e situação final em cada disciplina.
 * 
 * Lê o arquivo data/enrollments.txt e exibe grade, frequência consolidada e status.
 * 
 * @param studentEmail Email do aluno autenticado.
 */
void viewGrades(const std::string& studentEmail);


/**
 * @brief Permite ao aluno visualizar seu histórico detalhado de frequência (datas + P/A).
 * 
 * Exibe dados do arquivo data/attendance.txt em forma de tabela.
 * 
 * @param studentEmail Email do aluno autenticado.
 */
void viewAttendance(const std::string& studentEmail);






