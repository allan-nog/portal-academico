#pragma once
#include <string>

/**
 * @brief Gera um número de matrícula para alunos no formato:
 * [ano][mes][código curso][4 dígitos aleatórios]
 * Ex: 202507010874
 * 
 * @param courseCode Código do curso (ex: 1 para Engenharia de Software)
 * @return string com a matrícula gerada
 */
std::string generateStudentRegistration(int courseCode);

/**
 * @brief Gera um SIAPE para professores no formato:
 * [ano][mes][99][4 dígitos aleatórios]
 * Ex: 202507991235
 * 
 * @return string com o SIAPE gerado
 */
std::string generateTeacherSiape();