# Etapa 6 - Autenticação de Usuário e Persistência de Dados

## Objetivo

Implementar o sistema de login para usuários (alunos e professores), juntamente com as funções para salvar e carregar os dados dos usuários nos arquivos, garantindo persistência e validação.

---

## O que foi implementado

### 1. Salvamento dos usuários

- Criadas as funções `saveStudent` e `saveTeacher` para gravar os dados dos alunos e professores em arquivos separados (`data/students.txt` e `data/teachers.txt`).
- Os dados são salvos em formato CSV simplificado, usando `;` como delimitador para facilitar a leitura posterior.
- Após salvar, mensagens coloridas confirmam o sucesso da operação.

### 2. Carregamento dos usuários

- Implementada a função `loadUser` que recebe:
  - `email` do usuário,
  - `userType` ("student" ou "teacher"),
  - ponteiro opcional para um objeto `User` para preencher os dados carregados.
- A função lê linha a linha o arquivo correspondente ao tipo, separa os campos e verifica se o e-mail existe.
- Caso exista, carrega os dados no objeto `User` passado (se informado) e retorna `true`.
- Caso contrário, retorna `false`.

### 3. Registro de usuário (`registerUser`)

- Função que recebe o tipo de usuário a ser registrado.
- Realiza validação:
  - Nome: usa `validateName`
  - Email: usa `validateEmail` e verifica se já existe usando `loadUser`.
  - Senha: usa `validatePassword` e confirmação de senha.
- Após validações, cria o objeto `Student` ou `Teacher` com dados padrão para alguns campos (ex: matrícula `12345` e curso `"<desconhecido>"` para aluno).
- Salva o usuário com as funções `saveStudent` ou `saveTeacher`.

### 4. Login de usuário (`loginUser`)

- Solicita e-mail e senha ao usuário.
- Usa `loadUser` para carregar os dados, retornando erro caso o usuário não exista.
- Compara senha digitada com a senha salva.
- Retorna códigos para:
  - sucesso,
  - usuário não encontrado,
  - erro no carregamento,
  - senha incorreta.
- Mensagens coloridas para feedback visual.

---

## Exemplo de uso no código principal

```cpp
User userLogged;
int loginResult = loginUser("student", userLogged);
if (loginResult == 0) {
    // login ok, userLogged contém os dados
} else {
    // tratar erro
}