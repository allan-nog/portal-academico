# Stage 5 – Implementação do Sistema de Portais e Cadastro de Usuários

## Objetivo

Implementar os portais para os diferentes tipos de usuários (Aluno, Professor, Administrador) e criar a funcionalidade básica de cadastro de usuários, incluindo validação de dados.

---

## Atividades Realizadas

### 1. Menus de portais no `main.cpp`

- Implementação dos menus para:
  - Portal do Aluno (com opção de cadastro e login placeholder)
  - Portal do Professor (login placeholder)
  - Portal do Administrador (login placeholder)
- Navegação e tratamento de opções inválidas.
- Uso de cores e limpeza de console para melhor experiência.

### 2. Função de cadastro `registerUser` (módulo `UserUtils`)

- Entrada de dados com validações:
  - Nome completo com pelo menos duas palavras.
  - E-mail diferenciado para alunos (`@aluno.institution.br`) e professores (`@institution.br`).
  - Senha com confirmação e requisito mínimo de caracteres.
- Mensagens coloridas para erros e sucesso.
- Estrutura preparada para futura persistência dos dados.

### 3. Módulo de validação (`Validador`)

- Funções para validar:
  - Nome completo (mínimo duas palavras, só letras e espaços).
  - E-mail com regex específico para cada tipo de usuário.
  - Senha com regra simples de tamanho mínimo.

### 4. Utilitários do console (`ConsoleUtils`)

- Funções inline para alterar cor do texto e limpar console.
- Compatibilidade multiplataforma (Windows e Linux/macOS).

---

## Código Principal (`main.cpp`)

- Menu principal com escolha dos portais.
- Submenus para cada portal com funcionalidades básicas.
- Integração da função de cadastro de usuário no portal do aluno.
- Estrutura modular facilitando futuras expansões.

---

## Próximos Passos

- Implementar sistema de login com autenticação.
- Criar persistência dos dados em arquivos ou banco de dados.
- Implementar verificação de usuários duplicados no cadastro.
- Expandir funcionalidades nos portais (visualizar notas, frequências, etc).
- Adicionar controle de permissões e sessões.

---

## Observações

- Validações básicas já garantem dados consistentes.
- Interface simples, porém funcional, com feedback visual.
- Código estruturado para escalabilidade e manutenção facilitada.

---

## Conclusão

Esta etapa estabeleceu a fundação para interação do usuário com o sistema via portais dedicados e cadastro validado, abrindo caminho para implementações futuras de autenticação e gerenciamento de dados.
