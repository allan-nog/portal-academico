#include "Aluno.h"
#include <iostream>
using namespace std;

// Constructor
Aluno::Aluno(const std::string& name, const std::string& email, const std::string& password,
             int registration, const std::string& course, int period)
    : User(name, email, password), registration(registration), course(course), period(period) {}

// Getters
int Aluno::getRegistration() const noexcept { return registration; }
const std::string& Aluno::getCourse() const noexcept { return course; }
int Aluno::getPeriod() const noexcept { return period; }

// Setters
void Aluno::setRegistration(int newRegistration) noexcept { registration = newRegistration; }
void Aluno::setCourse(const std::string& newCourse) noexcept { course = newCourse; }
void Aluno::setPeriod(int newPeriod) noexcept { period = newPeriod; }

void Aluno::addDisciplina(const Disciplina& disciplina) {
    disciplinasMatriculadas.push_back(disciplina);
}

void Aluno::printInfo() const {
    User::printInfo();
    cout << "Matricula: " << registration << "\nCurso: " << course
         << "\nPeriodo: " << period << "\nDisciplinas matriculadas:\n";
    for (const auto& d : disciplinasMatriculadas) {
        cout << "- " << d.nome << " (" << d.cargaHoraria << "h)\n";
    }
}