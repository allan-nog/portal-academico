#pragma once
#include <string>
#include <vector>
#include "User.h"

/**
 * @brief Representa um professor do sistema acadêmico.
 * 
 * Herda de User, adicionando SIAPE e lista de disciplinas ministradas.
 */
class Teacher : public User {
private:
    int siape; ///< Número SIAPE (identificador de servidor público)
    std::vector<Course> teachingCourses; ///< Lista de disciplinas que o professor ministra
public:
    /**
     * @brief Construtor do Teacher
     * @param name Nome completo do professor
     * @param email Email institucional
     * @param password Hash da senha
     * @param siape Número SIAPE
     */
    Teacher(const std::string &name, const std::string &email, const std::string &password, int siape);

    int getSiape() const noexcept;
    void setSiape(int newSiape) noexcept;

    /**
     * @brief Adiciona uma disciplina à lista de disciplinas ministradas.
     * @param course Objeto Course representando a disciplina.
     */
    void addCourse(const Course &course);

    /**
     * @brief Imprime informações completas do professor.
     */
    void printInfo() const override;
};
