# Stage 8 – Segurança, Persistência e Gestão de Usuários

## Resumo das Implementações

### 1. Hash Seguro de Senhas com libsodium

- Integração da biblioteca libsodium para geração e verificação de hashes seguros usando Argon2id.
- Implementação das funções:
  - `std::string hashPassword(const std::string& password);`
  - `bool verifyPassword(const std::string& password, const std::string& hashedPassword);`
- Alteração do fluxo de cadastro para armazenar senhas hasheadas.
- Verificação da senha no login usando a função de verificação segura.

### 2. Persistência e Manipulação de Arquivos

- Garantia da existência dos arquivos `data/students.txt` e `data/teachers.txt` antes da leitura e escrita, através da função `ensureFileExists`.
- Funções de salvar e carregar usuários ajustadas para abrir arquivos com segurança.
- Correção da mensagem de erro ao abrir arquivos inexistentes.

### 3. Portais de Usuário

- Portal do Aluno e do Professor com menus funcionais.
- Portal do Administrador com autenticação simples (e-mail e senha fixos) e controle de tentativas.
- Submenus para funcionalidades futuras (atualização de dados, visualização de notas, etc), com mensagens indicativas.
- Controle de tentativas de login resetado corretamente a cada nova tentativa.

### 4. Melhorias na Experiência do Usuário

- Uso padronizado das funções de cores e limpeza de console para melhor UX no terminal.
- Tratamento de entradas inválidas e feedbacks visuais claros.
- Organização clara dos menus e fluxos.

---

## Arquivos Alterados

- `src/utils/UserUtils.cpp`
- `src/utils/UserUtils.h`
- `src/main.cpp`

---

## Próximos Passos Sugeridos

1. Implementar funcionalidades pendentes nos portais (atualizar dados, gerenciar notas, frequência, requerimentos).
2. Expandir portal do administrador para permitir cadastro e remoção reais de usuários.
3. Persistir bloqueios de login por tentativas incorretas.
4. Adicionar logs e auditoria básica.
5. Melhorar documentação e modularização do código.

---

## Observações

Este estágio representou um salto importante na segurança do sistema, adotando um padrão seguro para armazenamento de senhas e garantindo maior robustez na manipulação de arquivos. O sistema de portais já está funcional e preparado para expansão futura.

---

**FIM DO STAGE 8**

