# Etapa 4 – Implementação das Classes Principais (User, Student, Teacher)

## Objetivo

Implementar as classes centrais do portal acadêmico, responsáveis pelo gerenciamento de usuários, alunos e professores, com seus atributos e métodos básicos, seguindo princípios de orientação a objetos.

---

## Classes Implementadas

### 1. Classe `User`

- Representa um usuário genérico do sistema.
- Atributos protegidos: `name`, `email` e `password`.
- Métodos públicos:
  - Construtor parametrizado com passagem de strings por referência constante.
  - Getters e setters para os atributos (com uso de `const` e `noexcept`).
  - Método virtual `printInfo()` para impressão dos dados básicos.
  - Destrutor virtual padrão para garantir destruição correta em herança.

---

### 2. Classe `Student` (herda de `User`)

- Representa um aluno do portal.
- Atributos adicionais: `registration` (matrícula), `course` (curso), `period` (período), e vetor de `Course` representando disciplinas matriculadas.
- Métodos:
  - Construtor com passagem de parâmetros para inicializar todos os atributos.
  - Getters e setters para os atributos próprios.
  - Método `addCourse(const Course&)` para adicionar disciplinas.
  - Sobrescrita do método `printInfo()` para imprimir detalhes do aluno e suas disciplinas.

---

### 3. Classe `Teacher` (herda de `User`)

- Representa um professor do portal.
- Atributos adicionais: `siape` (identificador funcional) e vetor de `Course` para disciplinas lecionadas.
- Métodos:
  - Construtor com inicialização dos atributos.
  - Getters e setters para `siape`.
  - Método `addCourse(const Course&)` para adicionar disciplinas que leciona.
  - Sobrescrita do método `printInfo()` para exibir dados do professor e suas disciplinas.

---

## Organização do Código

- As classes estão organizadas dentro da pasta `src/core/`.
- As declarações em arquivos `.h` com include guards (`#pragma once`).
- As implementações em arquivos `.cpp` correspondentes.
- Estrutura de pastas:
src/
core/
User.h, User.cpp
Student.h, Student.cpp
Teacher.h, Teacher.cpp

- O arquivo `Course` é uma `struct` simples declarada em `User.h` para ser compartilhada entre as classes.

---

## Exemplo de Uso

No arquivo `src/main.cpp` foi criado um teste simples que:

- Instancia objetos `Teacher` e `Student`.
- Cria alguns cursos (`Course`).
- Adiciona disciplinas aos professores e alunos.
- Imprime as informações completas na tela, mostrando herança e composição.

---

## Como Compilar

Na raiz do projeto (`portal-academico`), rodar:

```bash
g++ -I./src -std=c++17 src/main.cpp src/core/*.cpp src/utils/*.cpp -o portal

Para executar:
./portal