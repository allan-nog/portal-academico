# Etapa 3 – Modelagem das Entidades e Estrutura de Dados

## Objetivo
Definir as classes principais, seus atributos e comportamentos (métodos), preparando para a implementação no código-fonte.

---

## 🎓 Classe `Aluno`

### Atributos:
- `string nome`
- `string matricula`
- `string email`
- `string senha`
- `map<string, float> notas` *(disciplina → nota)*
- `map<string, int> frequencia` *(disciplina → % presença)*

### Métodos:
- `void registrar()`  
- `bool autenticar(string login, string senha)`
- `void verNotas()`
- `void verFrequencia()`
- `void registrarRequerimento(string mensagem)`

---

## 👨‍🏫 Classe `Professor`

### Atributos:
- `string nome`
- `string siape`
- `string email`
- `string senha`
- `vector<string> disciplinas`

### Métodos:
- `bool autenticar(string login, string senha)`
- `void registrarNota(string matricula, string disciplina, float nota)`
- `void registrarFrequencia(string matricula, string disciplina, int percentual)`

---

## 🛠️ Classe `Administrador`

### Atributos:
- `string usuario`
- `string senha`

### Métodos:
- `bool autenticar(string login, string senha)`
- `void cadastrarAluno(Aluno novoAluno)`
- `void cadastrarProfessor(Professor novoProfessor)`
- `void removerUsuario(string tipo, string identificador)`
- `void verRequerimentos()`

---

## 📄 Classe `Requerimento`

### Atributos:
- `string matriculaAluno`
- `string mensagem`
- `string status` *(Pendente, Aprovado, Rejeitado)*

---

## 💾 Arquivos de Dados `.txt`

| Arquivo             | Conteúdo                               |
|-------------------- |----------------------------------------|
| `alunos.txt`        | matricula;nome;email;senha             |
| `professores.txt`   | siape;nome;email;senha                 |
| `disciplinas.txt`   | codigo;nome;siapeProfessor             |
| `notas.txt`         | matricula;disciplina;nota              |
| `frequencia.txt`    | matricula;disciplina;percentual        |
| `requerimentos.txt` | matricula;mensagem;status              |

---

## 🧠 Observações Técnicas

- **Login pode ser feito com e-mail ou matrícula/SIAPE**
- Dados serão salvos e carregados de arquivos `.txt`
- Orientação a objetos será aplicada desde o início
- Validação de e-mails e senhas pode usar **regex**
- Alocação dinâmica será usada para listas de objetos
- Erros de leitura, escrita e autenticação serão tratados com mensagens claras