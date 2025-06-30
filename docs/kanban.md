# Kanban do Projeto Portal Acadêmico 🎓

Um quadro simples para acompanhar as tarefas, focado no que está **a fazer**, **em andamento** e **concluído**.

---

## 📌 A FAZER
- Implementar funcionalidades do administrador:
  - Cadastro direto de aluno e professor
  - Visualizar usuários cadastrados
  - Remover usuários
  - Visualizar requerimentos
- Implementar sistema de requerimentos (aluno solicita, admin visualiza)
- Criar funcionalidades para o professor lançar notas e frequência
- Criar funcionalidades para o aluno visualizar notas e frequência
- Implementar atualização de dados de perfil (aluno e professor)
- Criar testes unitários para as classes e utilitários
- Melhorar modularidade e reaproveitamento de código (refatoração)
- Documentar novas etapas conforme avanço do projeto

---

## 🚧 EM ANDAMENTO
- Portal do administrador parcialmente implementado (login + menu, aguardando funcionalidades)
- Estrutura de menus para o aluno e professor completa, mas algumas opções ainda pendentes

---

## ✅ FEITO
- Definição da análise de requisitos e levantamento das funcionalidades
- Modelagem UML e estruturação das classes
- Estrutura de pastas do projeto (`src/core`, `src/utils`, `data`, `docs`, `tests`)
- Funções utilitárias para console (`setColor`, `resetColor`, `clearConsole`)
- Validações robustas na hora do cadastro de usuários
- Sistema de login para alunos, professores e administrador, com controle de tentativas
- Menus interativos implementados para aluno, professor e admin
- Documentação das etapas anteriores (`etapa1-analise.md`, `etapa2-fluxos.md`, `etapa3-initial-implementation.md`, `etapa4-classes.md`, `stage5-user-portal-implementations.md`)
- Criação de `TODO.md` para rastrear funcionalidades detalhadas

---

## 📝 Observações
- Dados atualmente armazenados em arquivos `.txt` (pasta `/data`), com possibilidade de migração futura para banco de dados
- O kanban deve ser atualizado conforme progresso, para manter a visão geral do projeto
- Priorização em manter código limpo, modular e documentado para facilitar manutenção e expansão futura
