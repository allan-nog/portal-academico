# TODO - Portal Acadêmico 🎯

Um checklist simplificado para acompanhar melhorias futuras e pendências técnicas no sistema.

---

## 🔥 Funcionalidades futuras
- [ ] Implementar bloqueio de login temporário (ex: 3 minutos após 5 tentativas falhadas)
- [ ] Criar logs de auditoria de login (sucesso / falha / IP ou terminal)
- [x] Implementar cadastro e login para o Administrador
- [ ] Permitir alteração de senha pelo usuário
- [ ] Adicionar recuperação de senha (via pergunta secreta ou token)
- [ ] Implementar sistema de permissões (restrições por tipo de usuário)

---

## 🚀 Melhorias no sistema
- [ ] Usar `chrono` ou `std::time` para controlar cooldowns e timestamps
- [ ] Refatorar funções duplicadas (como `saveStudent` / `saveTeacher`) para um utilitário genérico
- [ ] Melhorar as mensagens de erro e sucesso com ícones ou emojis no console
- [ ] Criar um menu de ajuda com instruções rápidas do sistema
- [ ] Fazer logging interno (em arquivos `.log`) para depuração

---

## 📝 Qualidade e organização do código
- [ ] Escrever testes unitários para `loadUser`, `loginUser` e `registerUser`
- [ ] Melhorar encapsulamento nas classes `Student` e `Teacher`
- [ ] Separar responsabilidades dos utilitários de console e validações
- [ ] Adicionar comentários Doxygen em todas as funções públicas
- [x] Implementar persistência com hash seguro (Argon2id via libsodium) para senhas
- [x] Garantir criação automática dos arquivos caso não existam (`ensureFileExists`)

---

## 💡 Observações
- Estas tarefas não são prioritárias para o MVP, mas garantirão um sistema mais robusto e pronto para evoluir.
- Atualizar este arquivo conforme forem surgindo novas ideias ou funcionalidades implementadas.

---

✅ **Versão atual:** protótipo funcional com cadastro e login (alunos, professores e administrador), hash seguro de senhas, persistência em arquivos `.txt` e menus completos no terminal.
