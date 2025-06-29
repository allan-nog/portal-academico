# Kanban do Projeto Portal Acadêmico 🎓

Um quadro simples para acompanhar as tarefas, focado no que está **a fazer**, **em andamento** e **concluído**.

---

## 📌 A FAZER
- Finalizar menus principais para aluno, professor e administrador
- Implementar sistema completo de login (autenticação e controle de sessão)
- Criar classes e funcionalidades para `Administrador`
- Implementar persistência avançada para administradores e funcionalidades futuras
- Validar entradas de dados com Regex (e-mail, matrícula, senha, SIAPE etc.)
- Criar testes unitários para funções principais (cadastro, login, manipulação de arquivos)
- Refatorar e melhorar modularidade, reaproveitamento e organização do código
- Documentar novas etapas e funcionalidades conforme o projeto avança

---

## 🚧 EM ANDAMENTO
- Implementação das classes base `User`, `Student` e `Teacher` com seus atributos e métodos
- Menus básicos no terminal com navegação entre portais (aluno, professor, administrador)
- Funções de cadastro de usuários com validações completas (nome, email, senha)
- Funções para salvar e carregar usuários em arquivos `.txt` com separador `;`
- Função genérica de login para alunos e professores com validação de senha
- Utilitários para manipulação de console (cores, limpeza de tela, menus)
- Documentação das etapas 1 a 6 (análise, fluxos, modelagem, implementação inicial, portais, cadastro e login)

---

## ✅ FEITO
- Definição da análise de requisitos e levantamento das funcionalidades
- Modelagem UML e estruturação das classes
- Estrutura de pastas do projeto definida (`src/core`, `src/utils`, `data`, `docs`, `tests`)
- Implementação das funções `setColor`, `resetColor` e `limparConsole`
- Menus interativos implementados com feedback colorido no terminal
- Cadastro de alunos e professores com validações de entrada
- Salvamento e carregamento de alunos e professores em arquivos `.txt`
- Função genérica de login implementada e integrada ao sistema
- Documentação das etapas iniciais criada (`etapa1-analise.md`, `etapa2-fluxos.md`, `etapa3-initial-implementation.md`, `etapa4-classes.md`, `etapa5-user-portal-implementations.md`, `etapa6-login.md`)

---

## 📝 Observações
- Dados atualmente armazenados em arquivos `.txt`, com possibilidade futura de migração para banco de dados
- Kanban será atualizado conforme progresso e revisão de prioridades
- Prioridade em manter código limpo, modular e documentado para facilitar manutenção e expansão
