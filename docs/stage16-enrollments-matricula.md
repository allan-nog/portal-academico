# stage16-enrollments-matricula.md

## 🚀 Etapa 16: Enrollments, Frequência e Matrícula

### 🔥 O que foi feito

- Criado novo fluxo para registrar notas e frequência buscando aluno **por matrícula ou e-mail**.
- Adicionados:
  - `loadStudentByEmail`
  - `loadStudentByRegistration`
- Funções `registerGrade` e `registerAttendance` agora:
  - Pedem se quer procurar aluno por matrícula ou por e-mail.
  - Sempre mostram matrícula, email e nome ao professor.
  - Calculam status com base nas regras:
    - **Aprovado:** nota ≥ 60 e frequência ≥ 75%
    - **Recuperação:** nota ≥ 30 e < 60 e frequência ≥ 50%
    - **Reprovado:** restante
- Atualizado arquivo `data/enrollments.txt` com o padrão:
email;disciplina;nota;frequencia;status

### 📂 Arquivos alterados
- `src/utils/UserUtils.h`  
- Adicionados protótipos `loadStudentByEmail` e `loadStudentByRegistration`.

- `src/utils/UserUtils.cpp`
- Implementadas funções `loadStudentByEmail` e `loadStudentByRegistration`.

- `src/utils/EnrollmentsUtils.cpp`
- Atualizadas funções `registerGrade` e `registerAttendance` para aceitar matrícula ou email.

### ✅ Regras consolidadas
- Matrícula gerada automaticamente ao cadastrar o aluno no padrão:  
AAAAMMCC#### (ano, mês, código do curso fixo, 4 dígitos aleatórios)

- Professores podem lançar:
- Notas de 0 a 100
- Frequência (P/F) por disciplina e data
- Sistema recalcula o status do aluno automaticamente após qualquer alteração.

---

## 💾 Persistência dos dados
- `data/students.txt` continua armazenando:
nome;email;hash_senha;matricula;curso;periodo

- `data/enrollments.txt` atualizado assim:
email;disciplina;nota;frequencia;status

- `data/attendance.txt`:
email;disciplina;data;P/F


---

## 🎯 Próximos passos sugeridos
- Implementar visualização de **histórico escolar do aluno**, exibindo notas e frequências.
- Criar menu do aluno para mostrar disciplinas, notas e frequência em forma de tabela bonita.
- Implementar `updateStudent` para permitir atualizar matrícula ou curso (restrito ao admin).

---

📌 **Versão do projeto:** `stage16`

