# Kanban do Projeto Portal Acadêmico 🎓

Um quadro simples para acompanhar as tarefas, focado no que está **a fazer**, **em andamento** e **concluído**.

---

## 📌 A FAZER
- Implementar sistema de lançamento de frequência pelo professor
- Implementar visualização consolidada dos requerimentos por aluno
- Criar testes unitários para as funções `registerGrade`, `registerAttendance`, `viewGrades`, `viewAttendance`
- Melhorar modularidade e reaproveitamento de código (refatoração)
- Documentar novas etapas conforme avanço do projeto

---

## 🚧 EM ANDAMENTO
- Portal do administrador parcialmente implementado (login + menu + CRUD usuários + requerimentos)
- Professores ainda aguardando telas de lançamento de frequência

---

## ✅ FEITO
- Definição da análise de requisitos e levantamento das funcionalidades
- Modelagem UML e estruturação das classes
- Estrutura de pastas do projeto (src/core, src/utils, src/portals, data, docs, tests)
- Funções utilitárias para console (setColor, resetColor, clearConsole, safeReadInt)
- Sistema de login para alunos, professores e administrador, com controle de tentativas
- Menus interativos implementados para aluno, professor e admin
- Cadastro automático de matrícula e SIAPE com padrão definido
- Registro de notas implementado (registerGrade)
- Visualização de notas e frequência implementada (viewGrades e viewAttendance)
- Documentação detalhada de cada estágio (`stage1` a `stage14`)

---

## 📝 Observações
- Dados atualmente armazenados em arquivos `.txt` na pasta `/data`
- Priorização em manter o código limpo, modular e documentado para facilitar manutenção e expansão futura
