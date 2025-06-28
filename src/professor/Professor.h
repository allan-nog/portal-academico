#pragma once
#include <string>
#include <vector>
#include "../usuario/Usuario.h"

class Teacher : public User {
private:
    int siape;
    std::vector<Disciplina> disciplinasLecionadas;
public:
    Teacher(const std::string& name, const std::string& email, const std::string& password, int siape);

    int getSiape() const noexcept;
    void setSiape(int newSiape) noexcept;

    void addDisciplina(const Disciplina& disciplina);
    void printInfo() const override;
};