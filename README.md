# Portal Acadêmico

Projeto acadêmico em C++ para gestão de um portal universitário via terminal.  
Contempla três subportais: Aluno, Professor e Administrador, com diferentes permissões e funcionalidades.

## 🚀 Funcionalidades atuais

- Menus interativos em terminal
- Portal do Aluno, Professor e Administrador
- Navegação simples e intuitiva
- Cores no console (multiplataforma)
- Limpeza automática do terminal

## 📁 Estrutura do projeto

.
├── data # Arquivos .txt simulando o banco de dados
├── docs # Documentação por etapas
├── src
│ ├── main.cpp # Código principal com menus
│ └── utils
│ └── ConsoleUtils.h
├── LICENSE
└── README.md

## ⚙️ Tecnologias e técnicas utilizadas

- C++ (compilação via g++)
- Orientação a Objetos (em breve)
- Manipulação de arquivos `.txt` para simular banco
- ANSI Escape Codes (Linux/macOS) e `SetConsoleTextAttribute` (Windows)
- `system("cls")` / `system("clear")` para limpeza do console

## 📌 Próximos passos

- Criar classes `Usuario`, `Aluno`, `Professor` e `Administrador`
- Implementar cadastro e login (armazenamento em `/data`)
- Sistema de requerimentos e controle de notas/frequência
- Validação via regex
- Posterior migração para banco de dados real

## 📜 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

