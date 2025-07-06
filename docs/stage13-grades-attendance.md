# stage13-grades-attendance.md

# Stage 13 - Sistema de Notas e Frequência 📚

Um resumo estruturado do que foi feito nesta etapa do projeto Portal Acadêmico.

---

## ✅ O que foi implementado
- Criado o **sistema de visualização de notas e frequência** para o aluno:
  - O aluno, ao fazer login, pode selecionar:
    ```
    [3] - Visualizar notas
    ```
    no menu do portal do aluno para ver suas disciplinas, notas, frequência e status (Aprovado ou Reprovado).

- Foi implementada a função:
  ```cpp
  void viewGradesAndAttendance(const std::string& studentEmail);
que:
Lê o arquivo data/enrollments.txt
Filtra por e-mail do aluno autenticado
Exibe todas as disciplinas, notas, frequência e status de aprovação ou reprovação.

## 📂 Design do arquivo enrollments.txt
O arquivo data/enrollments.txt segue o formato:
email;course_name;grade;attendance;status
Exemplo de conteúdo:
maria@exemplo.com;Engenharia de Software;8.50;92;Aprovado
joao@exemplo.com;Ciência da Computação;7.20;78;Aprovado
pedro@exemplo.com;Sistemas Operacionais;5.60;83;Reprovado

## 🔧 Ajustes no portal
O Portals.cpp foi atualizado para chamar viewGradesAndAttendance ao selecionar [3] - Visualizar notas no menu do aluno.

## 🚀 Próximos passos
Criar a funcionalidade do professor para registrar notas e frequência dos alunos, preenchendo o arquivo enrollments.txt.
Permitir que o professor visualize um resumo das notas já lançadas.
Futuramente, criar relatórios gerenciais para o administrador acompanhar o desempenho geral dos cursos.

## 📁 Arquivos modificados
src/utils/UserUtils.cpp: adicionada a função viewGradesAndAttendance.
src/utils/UserUtils.h: declaração da nova função.
src/portals/Portals.cpp: chamada da funcionalidade no menu do aluno.

