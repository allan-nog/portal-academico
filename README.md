# Portal Acadêmico - Sistema de Gestão via Terminal

## Visão Geral

O **Portal Acadêmico** é um sistema de gerenciamento acadêmico desenvolvido em C++ para execução via terminal. Ele oferece funcionalidades básicas para alunos, professores e administradores, permitindo cadastro, login, gerenciamento de disciplinas, registros de notas, frequência e requerimentos.

Este projeto tem como objetivo servir de base para aprendizado prático de desenvolvimento orientado a objetos, manipulação de arquivos, organização de código e construção de sistemas modulares.

## Tecnologias

- Linguagem: C++17
- Organização do código em módulos (core, utils)
- Persistência inicial em arquivos texto (`.txt`) na pasta `/data`
- Compatibilidade multiplataforma (Windows, Linux, macOS) para funcionalidades básicas de console (cores, limpeza de tela)

## Estrutura do Projeto

portal-academico/
├── data/ # Arquivos de dados do sistema (alunos, professores, cursos, etc)
├── docs/ # Documentação do projeto (análises, fluxos, etapas)
├── src/
│ ├── core/ # Classes principais: User, Student, Teacher, Admin, Request
│ ├── utils/ # Utilitários auxiliares (ConsoleUtils, Validador, MenuUtils)
│ └── main.cpp # Programa principal com testes e menus básicos
├── tests/ # Código de testes
├── README.md # Visão geral do projeto
└── LICENSE


## Funcionalidades (em desenvolvimento)

- Cadastro e login de usuários (alunos, professores, administradores)
- Gestão de disciplinas e cursos
- Registro de notas, frequência e requerimentos
- Menus interativos com feedback colorido no terminal
- Validações básicas de dados (planejadas)
- Persistência em arquivos texto

## Como Compilar e Executar

Navegue até a pasta raiz e execute:

```bash
g++ -I./src -std=c++17 src/main.cpp src/core/*.cpp src/utils/*.cpp -o portal
./portal
```

## 📜 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
