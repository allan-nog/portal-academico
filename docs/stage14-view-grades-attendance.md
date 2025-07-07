# Stage 14 - Visualização de notas e frequência 📊

## ✅ O que foi implementado

- Criadas duas funções utilitárias importantes para o aluno visualizar seu desempenho acadêmico:
  - `viewGrades`: permite que o aluno veja, de forma tabular, as disciplinas que está matriculado, suas notas finais, frequência consolidada e a situação (Aprovado/Reprovado).
  - `viewAttendance`: mostra o histórico detalhado de presença em cada aula, com data e status (P/A), também em formato organizado.

- Inclusão das chamadas no portal do aluno (`Portals.cpp`) para que o estudante possa acessar essas informações após o login.

---

## 🗂️ Estrutura dos dados lidos
- `data/enrollments.txt`
email;disciplina;nota;frequencia;status

- `data/attendance.txt`
email;disciplina;data;P/A;
---

## 📈 Exemplo da exibição no console

### viewGrades
---------- SUAS NOTAS ----------
Disciplina Nota Freq(%) Status
Algoritmos I 78.5 92.0 Aprovado
Banco de Dados 61.0 76.5 Aprovado
Estrutura de Dados 45.0 80.0 Reprovado

### viewAttendance
------ HISTÓRICO DE FREQUÊNCIA ------
Disciplina Data Status
Algoritmos I 2025-07-05 P
Algoritmos I 2025-07-12 A
Banco de Dados 2025-07-08 P
---

## 📝 Observações
- Foi utilizado `iomanip` para `setw` e `setprecision`, garantindo alinhamento elegante das colunas.
- Ainda é possível futuramente agrupar ou fazer totais, ou até gerar relatórios exportáveis.
- O código está modular, facilitando alterações para caso a universidade queira mudar o critério de aprovação ou o layout.
---

✅ **Status:** concluído, com testes no terminal.
