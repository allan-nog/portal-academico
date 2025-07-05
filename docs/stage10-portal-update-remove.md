# Stage 10 - Portal aprimorado 🚀

## 📌 O que foi feito

- Modularizamos o `main.cpp`, movendo cada portal (`studentPortal`, `teacherPortal` e `adminPortal`) para seus próprios arquivos `.cpp` e `.h`, deixando o `main` limpo e centralizado apenas para redirecionar.

- Implementamos a funcionalidade de **atualizar dados do usuário** (`updateUser`), que permite que alunos e professores alterem:
  - Nome (com validação)
  - Email (com checagem de duplicidade e formato)
  - Senha (com validação e hash)

- Implementamos a funcionalidade de **remover usuário** (`removeUser`), disponível no portal do administrador. Ele pede o email e remove o registro do arquivo `.txt` correspondente.

- Todas essas funcionalidades respeitam o fluxo colorido do console (`setColor`, `resetColor`), além de mensagens claras ao usuário.

---

## 📁 Estrutura do projeto neste stage
src/
├── core/
│ ├── Student.cpp / .h
│ └── Teacher.cpp / .h
├── utils/
│ ├── ConsoleUtils.h
│ ├── UserUtils.cpp / .h
│ └── ValidationUtils.h
├── portals/
│ ├── StudentPortal.cpp / .h
│ ├── TeacherPortal.cpp / .h
│ └── AdminPortal.cpp / .h
└── main.cpp
---

## ✅ Resultado deste stage

- Portais mais organizados e fáceis de manter.
- Possibilidade de o usuário atualizar seus dados de forma segura e validada.
- Admin agora consegue remover alunos ou professores pelo email.
---

## 🔥 Próximos passos

- Criar o sistema de requerimentos (aluno solicita, admin visualiza), próximo stage.
---
