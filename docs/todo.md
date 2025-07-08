# TODO - Portal Acadêmico 🎯

Um checklist simplificado para acompanhar melhorias futuras e pendências técnicas no sistema.

---

## 🔥 Funcionalidades futuras
- [ ] Exportar dados de frequência, notas e status para CSV
- [ ] Criar relatórios detalhados por aluno e por disciplina
- [ ] Permitir que professor cadastre novas disciplinas no sistema
- [ ] Criar tela/menu do admin para adicionar disciplinas aos cursos
- [ ] Implementar busca avançada nos requerimentos (por email, por data)

---

## 🚀 Melhorias no sistema
- [ ] Centralizar lógica de cálculo do status (para evitar repetição futura)
- [ ] Refatorar `registerGrade` e `registerAttendance` para modularizar partes comuns
- [ ] Usar enums ou constantes para status ao invés de strings livres
- [ ] Adicionar logs de ações do professor (quem lançou nota, frequência)

---

## 📝 Qualidade e organização do código
- [ ] Adicionar testes unitários para validação do status (Aprovado/Recuperação/Reprovado)
- [ ] Adicionar comentários Doxygen consistentes nos novos métodos
- [ ] Melhorar separação de responsabilidades em futuros controllers de domínio

---

✅ **Versão atual:** Portal funcional com cadastro, login, registro de notas, frequência e status automatizado, suportando recuperação.
