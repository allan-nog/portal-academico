# 📚 Stage 7 - Portal Acadêmico: Login do Administrador e Estrutura Completa dos Portais

## 🔥 O que foi implementado nesta etapa

### ✅ Portal do Administrador
- Criado o portal do administrador com login hardcoded (`admin@admin.com` / `admin123`).
- Implementado controle de 3 tentativas, que reinicia se o administrador sair e tentar novamente.
- Montado um sub-menu para o administrador, com as opções:
  - [1] Cadastrar aluno
  - [2] Cadastrar professor
  - [3] Atualizar dados (futuro)
  - [4] Visualizar usuários
  - [5] Remover usuário
  - [6] Visualizar requerimentos
  - [0] Logout
- Todas essas funcionalidades ainda estão marcadas como **não implementadas**, mas o fluxo e as mensagens já foram preparados.

### ✅ Ajustes nos portais de aluno e professor
- Cada portal tem agora menus internos (sub-menus) depois do login, com opções como:
  - Visualizar perfil
  - Atualizar dados (placeholder)
  - Visualizar notas
  - Visualizar frequência
  - Registrar requerimento (aluno)
  - Registrar notas / frequência (professor)
- O logout funciona limpando a tela e retornando ao menu anterior.

### ✅ Correções e melhorias
- Corrigido bug do `attempts` do admin não resetar ao retornar ao menu principal.
- Melhoria nas cores para padronizar todos os portais (azul para headers, verde para inputs, vermelho para erros, amarelo para mensagens positivas).
- `clearConsole()` usado para limpar a tela em momentos estratégicos, mantendo uma UX fluida.

### ✅ Atualização do Kanban
- Criado o `KANBAN.md` atualizado para refletir a fase atual do projeto.
- Organizado o que está **feito**, **em andamento** e o que ainda está **a fazer**, garantindo rastreabilidade.

---

## 📂 Estrutura do projeto após este estágio
src/
├─ core/
│ ├─ User.h / User.cpp
│ ├─ Student.h / Student.cpp
│ └─ Teacher.h / Teacher.cpp
├─ utils/
│ ├─ ConsoleUtils.h / .cpp
│ ├─ UserUtils.h / .cpp
│ └─ Validador.h / .cpp
data/
├─ students.txt
├─ teachers.txt
docs/
├─ etapa1-analise.md
├─ etapa2-fluxos.md
├─ etapa3-initial-implementation.md
├─ etapa4-classes.md
├─ stage5-user-portal-implementations.md
├─ stage6-login-features.md
├─ stage7-portal-admin-login-and-structure.md ← (este arquivo)
├─ KANBAN.md
└─ TODO.md
---

## 🚀 Próximos passos
- Implementar as funcionalidades reais do admin:
  - Cadastrar aluno/professor direto (via admin)
  - Visualizar todos os usuários cadastrados
  - Remover usuários
  - Visualizar requerimentos
- Criar persistência dos requerimentos em arquivo (`data/requests.txt`).
- Adicionar exibição real das notas e frequência do aluno, e telas para o professor lançar esses dados.
- Escrever testes unitários básicos para as principais classes (`User`, `Student`, `Teacher`).
---

## 💬 Observações finais
Estamos avançando de forma modular e iterativa.  
A arquitetura permite facilmente expandir as funcionalidades sem comprometer o que já foi feito, e os menus foram projetados para dar suporte a qualquer nova feature.

O foco continua em:
- Manter o **código limpo e organizado**,
- Usar cores e menus amigáveis para o usuário,
- Garantir que o projeto esteja sempre **executável e estável** em cada etapa.
---

🎉 **Fim do Stage 7**.  
Pronto para avançarmos para o Stage 8.
