# TODO - Portal Acadêmico 🎯

Um checklist simplificado para acompanhar melhorias futuras e pendências técnicas no sistema.

---

## 🔥 Funcionalidades futuras
- [ ] Implementar bloqueio de login temporário (ex: 3 minutos após 5 tentativas falhadas)
- [ ] Criar logs de auditoria de login (sucesso / falha / IP ou terminal)
- [ ] Permitir alteração de senha pelo usuário
- [ ] Adicionar recuperação de senha (via pergunta secreta ou token)
- [ ] Implementar sistema de permissões (restrições por tipo de usuário)

---

## 🚀 Melhorias no sistema
- [ ] Usar `chrono` ou `std::time` para controlar cooldowns e timestamps
- [ ] Refatorar funções duplicadas (por exemplo, salvar e atualizar arquivos .txt)
- [ ] Criar um menu de ajuda com instruções rápidas do sistema
- [ ] Fazer logging interno (em arquivos `.log`) para depuração
- [ ] Melhorar as mensagens do console com ícones ou emojis

---

## 📝 Qualidade e organização do código
- [ ] Escrever testes unitários para `registerGrade`, `registerAttendance`, `viewGrades`, `viewAttendance`
- [x] Validar campos e tratar entradas incorretas com `safeReadInt`
- [x] Organizar geração automática de matrícula e SIAPE
- [x] Implementar visualização das notas e frequência do aluno

---

## 💡 Observações
- Estas tarefas não são prioritárias para o MVP, mas garantirão um sistema mais robusto e pronto para evoluir.
- Atualizar este arquivo conforme surgirem novas ideias ou forem concluídas funcionalidades.

---

✅ **Versão atual:** sistema com cadastros, login, menus completos e visualização de notas + frequência.
