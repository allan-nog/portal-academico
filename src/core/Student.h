#pragma once
#include <string>
#include <vector>
#include "User.h"

/**
 * @brief Representa um estudante do sistema acadêmico.
 * 
 * Herda de User, adicionando matrícula, curso, período e lista de disciplinas matriculadas.
 */
class Student : public User {
private:
    int registration; ///< Número de matrícula do aluno
    std::string course; ///< Curso que o aluno está matriculado
    int period; ///< Período atual (ex: 1, 2, 3...)
    std::vector<Course> enrolledCourses; ///< Lista de disciplinas em que o aluno está matriculado
public: 
    /**
     * @brief Construtor do Student
     * @param name Nome completo do aluno
     * @param email Email institucional ou pessoal
     * @param password Hash da senha
     * @param registration Número de matrícula
     * @param course Curso que o aluno está matriculado
     * @param period Período atual
     */
    Student(const std::string &name, const std::string &email, const std::string &password, int registration, const std::string &course, int period);

    int getRegistration() const noexcept;
    const std::string& getCourse() const noexcept;
    int getPeriod() const noexcept;

    void setRegistration(int newRegistration) noexcept;
    void setCourse(const std::string &newCourse) noexcept;
    void setPeriod(int newPeriod) noexcept;

    /**
     * @brief Adiciona uma disciplina à lista de cursos matriculados.
     * @param course Objeto Course representando a disciplina.
     */
    void addCourse(const Course &course);

    /**
     * @brief Imprime informações completas do estudante.
     */
    void printInfo() const override;
};
