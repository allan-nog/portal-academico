#pragma once
#include <string>
#include <vector>

/**
 * @brief Estrutura que representa um item do currículo acadêmico (disciplina obrigatória).
 */
struct CurriculumItem {
    std::string courseName;  ///< Nome do curso (ex: Engenharia de Software)
    int period;              ///< Período (ex: 1,2,3...)
    std::string code;        ///< Código da disciplina (ex: C01)
    std::string name;        ///< Nome completo da disciplina
};

/**
 * @brief Carrega o currículo acadêmico a partir de um arquivo .txt.
 * 
 * O formato do arquivo deve ser:
 * Curso;Período;Código;Nome
 * 
 * Exemplo:
 * Engenharia de Software;1;C01;Algoritmos e Estrutura de Dados I
 *
 * @param filePath Caminho do arquivo curriculum.txt
 * @return Vector com todas as disciplinas obrigatórias carregadas
 */
std::vector<CurriculumItem> loadCurriculum(const std::string& filePath);

/**
 * @brief Lista todas as disciplinas obrigatórias de um dado curso e período.
 * 
 * Pode ser usado no portal do aluno para mostrar o que ele deve cursar no período atual.
 * 
 * @param curriculum Estrutura completa do currículo
 * @param course Nome do curso (ex: Engenharia de Software)
 * @param period Período atual do aluno
 * @return Vector com as disciplinas encontradas
 */
std::vector<CurriculumItem> listMandatoryCourses(const std::vector<CurriculumItem>& curriculum, const std::string& course, int period);

/**
 * @brief Verifica se uma disciplina faz parte da grade obrigatória do curso e período.
 * 
 * Pode ser usado para garantir que o professor só lance nota/frequência de disciplinas válidas
 * que o aluno esteja realmente matriculado.
 * 
 * @param curriculum Estrutura completa do currículo
 * @param course Nome do curso
 * @param period Período
 * @param code Código da disciplina (ex: C01)
 * @return true se disciplina encontrada, false caso contrário
 */
bool isDisciplineInCurriculum(const std::vector<CurriculumItem>& curriculum, const std::string& course, int period, const std::string& code);
