# 🎓 Portal Acadêmico - Sistema de Gestão via Terminal

## 📘 Visão Geral

O **Portal Acadêmico** é um sistema de gerenciamento acadêmico desenvolvido em **C++17**, executado via terminal, voltado para o gerenciamento de **alunos**, **professores** e **administradores**. O sistema oferece funcionalidades completas, incluindo:

- Cadastro e login com validação de dados
- Registro de **notas** e **frequência**
- Manipulação de **requerimentos**
- Atualização segura de dados com verificação de senha
- Leitura e validação de disciplinas com base na **grade curricular oficial**

Este projeto serve como base para estudo prático de **POO em C++**, **manipulação de arquivos**, **validação de entrada**, **design modular** e **cross-compilation**.

---

## ⚙️ Tecnologias Utilizadas

- **Linguagem**: C++17  
- **Hash de senha**: libsodium (com Argon2)  
- **Estrutura modular**: `core/`, `utils/`, `portals/`  
- **Persistência**: Arquivos `.txt` dentro da pasta `/data`  
- **Terminal interativo**: Cores e limpeza de tela multiplataforma  
- **Cross-platform**: Compatível com Linux, Windows e macOS  

---

## 📁 Estrutura do Projeto

```
portal-academico/
├── data/               # Dados persistentes (.txt)
│   ├── curriculum.txt  # Grade curricular obrigatória
│   ├── students.txt    # Alunos cadastrados
│   ├── teachers.txt    # Professores cadastrados
│   ├── grades.txt      # Notas registradas
│   ├── attendance.txt  # Frequências registradas
│   └── requests.txt    # Requerimentos
├── docs/               # Documentação complementar (opcional)
├── src/
│   ├── core/           # Classes principais: User, Student, etc.
│   ├── utils/          # Utilitários: ConsoleUtils, Validators, etc.
│   ├── portals/        # Portais para aluno, professor e admin
│   └── main.cpp        # Entrada do programa
├── tests/              # Pasta reservada para testes
├── LICENSE             # Licença MIT
└── README.md           # Este arquivo
```

---

## 🎯 Funcionalidades Completas

### 👤 Alunos
- Registro com validação de nome, e-mail e senha  
- Login via e-mail e senha  
- Visualização e atualização de perfil  
- Visualização de notas e frequência  
- Envio de requerimentos  

### 👨‍🏫 Professores
- Login via e-mail e senha  
- Registro de **notas** e **frequência** com validação automática pelo currículo  
- Atualização de dados com verificação de senha  
- Segurança reforçada por hash Argon2  

### 🛡️ Administrador
- Login fixo: `admin@admin.com / admin123`  
- Cadastro de alunos e professores  
- Atualização de qualquer usuário (sem senha atual)  
- Visualização e remoção de usuários  
- Listagem de requerimentos pendentes  

### 📚 Currículo Acadêmico
- Lido de `data/curriculum.txt` no formato:  
  ```
  Curso;Período;Código;Nome
  ```
- Validação de disciplinas no momento do lançamento de notas/frequência  

---

## 🚀 Como Compilar e Executar

### ✅ Linux/macOS

```bash
g++ -I./src -std=c++17 src/main.cpp src/core/*.cpp src/utils/*.cpp src/portals/*.cpp -o portal -lsodium
./portal
```

### 🪟 Windows (com cross-compilação no Linux)

#### 1. Instale o compilador cross-platform:

```bash
sudo apt install g++-mingw-w64
```

#### 2. Compile com:

```bash
x86_64-w64-mingw32-g++ -std=c++17 -static -I./src src/main.cpp src/core/*.cpp src/utils/*.cpp src/portals/*.cpp -o portal_academico.exe -lsodium
```

#### 3. Para executar no Windows:
- Transfira o `portal_academico.exe` e a pasta `data/` para o Windows.
- Dê duplo clique no `.exe` ou execute via terminal `cmd`.

> **Obs.:** a flag `-static` permite gerar um `.exe` independente, sem depender de DLLs externas.

---

## 🛠️ Requisitos

- g++ 7+ com suporte a C++17  
- `libsodium` instalado para hashing  
- Terminal com suporte a ANSI (para cores)  
- Para Windows, use compilador MinGW ou WSL  

---

## 📜 Licença

Distribuído sob a licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais informações.

---

## 🙋‍♂️ Sobre o Projeto

Este projeto foi desenvolvido com fins educacionais, reforçando boas práticas de:

- Modularização  
- Validação e segurança  
- Manipulação de arquivos  
- Separação de responsabilidades por tipo de usuário  
- Interface via terminal com feedback visual

---

💡 **Próximos passos sugeridos**:
- Implementar banco de dados (SQLite ou MySQL)
- Criar interface gráfica (com Qt ou Web)
- Versão Web com backend C++ ou integração via REST
