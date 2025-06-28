#include "Professor.h"
#include <iostream>
using namespace std;

// Constructor
Teacher::Teacher(const std::string& name, const std::string& email, const std::string& password, int siape)
    : User(name, email, password), siape(siape) {}

// Getters
int Teacher::getSiape() const noexcept { return siape; }

// Setters
void Teacher::setSiape(int newSiape) noexcept { siape = newSiape; }

void Teacher::addDisciplina(const Disciplina& disciplina) {
    disciplinasLecionadas.push_back(disciplina);
}

void Teacher::printInfo() const {
    User::printInfo();
    cout << "SIAPE: " << siape << "\nDisciplinas lecionadas:\n";
    for (const auto& d : disciplinasLecionadas) {
        cout << "- " << d.nome << " (" << d.cargaHoraria << "h)\n";
    }
}