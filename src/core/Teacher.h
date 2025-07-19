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
    std::string siape; ///< Número SIAPE (identificador de servidor público)
    std::vector<Course> teachingCourses; ///< Lista de disciplinas ministradas pelo professor
public:
    /**
     * @brief Construtor padrão (necessário para criar objetos vazios e depois preencher).
     */
    Teacher() : siape("") {}

    /**
     * @brief Construtor do Teacher.
     * @param name Nome completo do professor
     * @param email Email institucional
     * @param password Hash da senha
     * @param siape Número SIAPE
     */
    Teacher(const std::string &name, const std::string &email, const std::string &password, const std::string &siape);

    /// @return SIAPE do professor
    std::string getSiape() const noexcept;
    /// Define um novo SIAPE
    void setSiape(const std::string &newSiape) noexcept;

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
