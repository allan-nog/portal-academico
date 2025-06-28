# Kanban do Projeto Portal Acadêmico 🎓

Um quadro simples para acompanhar as tarefas, focado no que está **a fazer**, **em andamento** e **concluído**.

---

## 📌 A FAZER
- Criar classe base `Usuario` (nome, email, senha)
- Criar classe `Aluno` herdando `Usuario`
- Criar classe `Professor` herdando `Usuario`
- Criar classe `Administrador`
- Implementar persistência em arquivos `.txt` para:
    - Alunos
    - Professores
    - Notas
    - Frequência
    - Requerimentos
- Implementar login e registro:
    - Registro de aluno via e-mail
    - Login do aluno (email/matrícula)
    - Login do professor (email/SIAPE)
    - Login do administrador
- Implementar menus pós-login:
    - Menu do aluno (ver notas, frequência, registrar requerimento)
    - Menu do professor (registrar notas, frequência)
    - Menu do administrador (cadastrar/remover usuários, ver requerimentos)
- Validar entradas com Regex
- Tratar erros e exceções ao abrir/ler/gravar arquivos
- Criar documentação `README.md` final detalhada

---

## 🚧 EM ANDAMENTO
- Menus iniciais com cor e limpeza do console
- Organização do projeto em pastas (`src`, `docs`, `data`, `utils`)

---

## ✅ FEITO
- Estrutura de pastas do projeto definida
- ConsoleUtils com:
    - Funções inline `setColor`, `resetColor`, `limparConsole`
- Menu principal com chamadas para:
    - Portal do aluno
    - Portal do professor
    - Portal do administrador
- Documentação das etapas:
    - `etapa1-analise.md`
    - `etapa2-fluxos.md`
    - `etapa3-modelagem.md`

---

## 📝 Observações
- Por enquanto, todos os dados serão salvos em arquivos `.txt`. 
- Posteriormente o projeto poderá migrar para banco de dados.
- Sempre atualizar este Kanban ao iniciar / concluir tarefas.
