#include <iostream>
#include "../src/core/Teacher.h"
#include "../src/core/Student.h"

int main() {
    // Criando um professor
    Teacher prof("João Silva", "joao.silva@example.com", "123456", 12345);

    // Criando um aluno
    Student aluno("Maria Souza", "maria.souza@example.com", "senha123", 2021001, "Engenharia de Software", 3);

    // Criar alguns cursos
    Course math{"Matemática", 60};
    Course prog{"Programação C++", 80};
    Course hist{"História", 40};

    // Adicionar cursos para professor e aluno
    prof.addCourse(math);
    prof.addCourse(prog);

    aluno.addCourse(prog);
    aluno.addCourse(hist);

    // Mostrar informações
    prof.printInfo();
    aluno.printInfo();

    return 0;
}
