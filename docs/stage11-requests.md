# Stage 11 - Sistema de requerimentos 📑

## 📌 O que foi feito

- Implementamos o **sistema de requerimentos**, que permite:
  - **Aluno registrar um requerimento** via `createRequest`, descrevendo o motivo ou mensagem.
  - **Administrador visualizar todos os requerimentos** via `listRequests`.

- Os requerimentos são salvos no arquivo `data/requests.txt`, cada linha no formato: email_do_aluno;mensagem;data hora
---

## 🚀 Funcionalidades implementadas

- `createRequest`:
  - Pede o email do aluno e o texto do requerimento.
  - Armazena em `requests.txt` com persistência.

- `listRequests`:
  - Admin visualiza todos os requerimentos no console, formatados em amarelo.
---

## ✅ Resultado deste stage

- O sistema agora suporta fluxos administrativos reais: alunos podem abrir solicitações e o admin tem uma fila para visualizar.

- Código totalmente modular, mantendo o padrão do projeto.
---

## 🔥 Próximos passos

- Pensar em aceitar / recusar requerimentos no futuro.
- Seguir com as funcionalidades restantes do admin, professor e aluno.
---

