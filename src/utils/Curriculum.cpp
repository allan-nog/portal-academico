#include "Curriculum.h"
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief Carrega o currículo a partir de um arquivo .txt.
 */
std::vector<CurriculumItem> loadCurriculum(const std::string& filePath) {
    std::vector<CurriculumItem> curriculum;
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Erro ao abrir o arquivo do currículo: " << filePath << "\n";
        return curriculum;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream ss(line);
        std::string courseName, periodStr, code, name;

        getline(ss, courseName, ';');
        getline(ss, periodStr, ';');
        getline(ss, code, ';');
        getline(ss, name);

        int period = std::stoi(periodStr);

        curriculum.push_back({courseName, period, code, name});
    }

    return curriculum;
}

/**
 * @brief Lista todas as disciplinas obrigatórias do curso e período.
 */
std::vector<CurriculumItem> listMandatoryCourses(const std::vector<CurriculumItem>& curriculum,
                                                 const std::string& course,
                                                 int period) {
    std::vector<CurriculumItem> result;
    for (const auto& item : curriculum) {
        if (item.courseName == course && item.period == period) {
            result.push_back(item);
        }
    }
    return result;
}

/**
 * @brief Verifica se disciplina faz parte da grade obrigatória.
 */
bool isDisciplineInCurriculum(const std::vector<CurriculumItem>& curriculum,
                              const std::string& course,
                              int period,
                              const std::string& code) {
    for (const auto& item : curriculum) {
        if (item.courseName == course && item.period == period && item.code == code) {
            return true;
        }
    }
    return false;
}
