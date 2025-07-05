# TODO - Portal Acadêmico 🎯

Um checklist simplificado para acompanhar melhorias futuras e pendências técnicas no sistema.

---

## 🔥 Funcionalidades futuras
- [ ] Implementar bloqueio de login temporário (ex: 3 minutos após 5 tentativas falhadas)
- [ ] Criar logs de auditoria de login (sucesso / falha / IP ou terminal)
- [ ] Permitir alteração de senha pelo usuário sem trocar outros dados
- [ ] Adicionar recuperação de senha (via pergunta secreta ou token)
- [ ] Implementar sistema de permissões (restrições por tipo de usuário)
- [ ] Aceitar ou recusar requerimentos pelo admin
- [ ] Criar menu de ajuda com instruções rápidas do sistema

---

## 🚀 Melhorias no sistema
- [x] Refatorar funções duplicadas (`saveStudent` / `saveTeacher`) para melhor consistência (já parcialmente modularizado)
- [x] Usar `safeReadInt` para proteger entradas e evitar crash do programa
- [ ] Usar `chrono` ou `std::time` para controlar cooldowns e timestamps futuros
- [ ] Fazer logging interno (em arquivos `.log`) para depuração
- [ ] Melhorar as mensagens de erro e sucesso com ícones ou emojis no console

---

## 📝 Qualidade e organização do código
- [ ] Escrever testes unitários para `loadUser`, `loginUser`, `registerUser` e agora `updateUser`, `removeUser`, `createRequest`
- [ ] Melhorar encapsulamento nas classes `Student` e `Teacher`
- [ ] Adicionar comentários Doxygen em todas as funções públicas e novos utilitários
- [ ] Documentar futuras regras de negócio (requerimentos, notas, frequência)

---

## 💡 Observações
- Estas tarefas não são críticas para o MVP atual, mas garantirão um sistema mais robusto, pronto para deploy ou expansão futura.
- Atualizar este arquivo conforme novas funcionalidades forem implementadas ou novas ideias surgirem.

---

✅ **Versão atual:** protótipo funcional com cadastro, login, atualização, remoção e sistema de requerimentos.
