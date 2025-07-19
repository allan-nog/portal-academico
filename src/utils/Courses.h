#pragma once
#include <vector>
#include <string>

/**
 * @brief Retorna a lista fixa de cursos disponíveis no sistema acadêmico.
 * 
 * Esta função é usada para validar o curso no momento do cadastro de estudantes.
 * 
 * Cursos disponíveis:
 * - Engenharia de Software
 * - Ciência da Computação
 * - Engenharia de Computação
 * - Sistemas de Informação
 * - Redes de Computadores
 * - Análise e Desenvolvimento de Sistemas
 * - Segurança da Informação
 * - Ciência de Dados
 * 
 * @return Referência constante para vetor de strings com os nomes dos cursos.
 */
inline const std::vector<std::string>& getAvailableCourses() {
    static const std::vector<std::string> courses = {
        "Engenharia de Software",
        "Ciência da Computação",
        "Engenharia de Computação",
        "Sistemas de Informação",
        "Redes de Computadores",
        "Análise e Desenvolvimento de Sistemas",
        "Segurança da Informação",
        "Ciência de Dados"
    };
    return courses;
}
