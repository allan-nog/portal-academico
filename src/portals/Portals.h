#pragma once
#include <vector>
#include "../utils/Curriculum.h"

/**
 * @brief Portal do aluno: menu de registro, login e funcionalidades.
 * 
 * @param curriculum Vetor com a grade curricular carregada do arquivo.
 */
void studentPortal(const std::vector<CurriculumItem>& curriculum);

/**
 * @brief Portal do professor: login e funcionalidades (registrar notas e frequência).
 * 
 * @param curriculum Vetor com a grade curricular carregada do arquivo.
 */
void teacherPortal(const std::vector<CurriculumItem>& curriculum);

/**
 * @brief Portal do administrador: login fixo e funcionalidades administrativas.
 * 
 * @param curriculum Vetor com a grade curricular carregada do arquivo.
 */
void adminPortal(const std::vector<CurriculumItem>& curriculum);
