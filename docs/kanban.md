# Kanban do Projeto Portal Acadêmico 🎓

Um quadro simples para acompanhar as tarefas, focado no que está **a fazer**, **em andamento** e **concluído**.

---

## 📌 A FAZER
- Criar relatórios detalhados para exibir notas, frequência e status por disciplina e por aluno
- Implementar sistema para professor lançar disciplinas e vincular aos cursos
- Permitir cadastro de novas disciplinas pelo administrador
- Melhorar modularidade do `registerGrade` e `registerAttendance` para evitar repetição
- Implementar exportação de dados (CSV ou JSON)
- Criar testes unitários específicos para cálculo do status
- Documentar novas etapas conforme avanço do projeto

---

## 🚧 EM ANDAMENTO
- Sistema de requerimentos inicial funcionando (cadastro e visualização simples), falta refinar buscas e filtragem

---

## ✅ FEITO
- Cadastro e login de alunos, professores e admin com hash seguro (Argon2id)
- Gerador automático de matrícula e SIAPE seguindo padrão numérico
- Cadastro com cursos pré-definidos
- Sistema de frequência com percentual calculado automaticamente
- Registro de notas atualizado para 0-100, recalculando situação do aluno (aprovado, recuperação ou reprovado)
- Persistência em arquivos `.txt` para usuários, matrículas, frequência e requerimentos
- Lógica robusta de status final implementada em `registerGrade` e `registerAttendance`

---

## 📝 Observações
- Prioridade agora é exibir relatórios claros para consolidar dados para alunos, professores e admin.
- O kanban deve ser atualizado sempre que novas features forem planejadas ou concluídas.
