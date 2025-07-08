#pragma once
#include <vector>
#include <string>

/**
 * @brief Retorna uma lista fixa com os cursos disponíveis do sistema.
 * 
 * Cursos disponíveis:
 * - Engenharia de Software
 * - Ciência da Computação
 * - Engenharia de Computação
 * - Sistemas de Informação
 * - Redes de Computadores
 * - Análise e Desenvolvimento de Sistemas
 * - Segurança da informação
 * - Ciência de Dados
 * 
 * Usado para garantir dados válidos no cadastro de alunos.
 * 
 * @return const std::vector<std::string>& com os nomes dos cursos.
 */
inline const std::vector<std::string>& getAvailableCourses() {
    static const std::vector<std::string> courses = {
        "Engenharia de Software",
        "Ciência da Computação",
        "Engenharia de Computação",
        "Sistemas de Informação",
        "Redes de Computadores",
        "Análise e Desenvolvimento de Sistemas",
        "Segurança da informação",
        "Ciência de Dados"
    };
    return courses;
}
