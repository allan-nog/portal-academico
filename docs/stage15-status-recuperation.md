# Stage 15 - Status com Recuperação 🚦

## ✅ O que foi feito

- Implementamos o sistema completo de status do aluno em cada disciplina, agora considerando:
  - **Aprovado**: nota ≥ 60 e frequência ≥ 75%
  - **Recuperação**: nota ≥ 30 e < 60 e frequência ≥ 50%
  - **Reprovado**: caso contrário
- A lógica foi aplicada de forma consistente nas funções:
  - `registerGrade`: ao registrar ou atualizar uma nota, já recalcula status considerando a frequência.
  - `registerAttendance`: ao lançar presença/falta, já recalcula status considerando a nota.

## 💾 Impacto nos dados
- O arquivo `data/enrollments.txt` agora salva:
email_aluno;disciplina;nota;frequencia;status
Exemplo:
joao@gmail.com;Algoritmos;65;80.0;Aprovado
maria@gmail.com;POO;55;60.0;Recuperacao

## 📊 Consistência
- O status é calculado **apenas nos dois pontos principais**: lançamento de nota e lançamento de frequência, garantindo que não existam discrepâncias.
---

## 🚀 Próximos passos
- Criar comandos específicos para listar **notas + status** por disciplina.
- Implementar um relatório geral por aluno mostrando todas as disciplinas, notas, frequência e status.
---

✅ **Versão atual:** sistema de avaliações robusto, com suporte a aprovação, recuperação e reprovação de acordo com critérios claros.
