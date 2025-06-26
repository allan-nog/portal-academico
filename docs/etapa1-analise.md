# Etapa 1 – Análise e Levantamento de Requisitos

## Objetivo
Definir os requisitos funcionais e não-funcionais do portal acadêmico.

## Subportais definidos
- Portal do Aluno
- Portal do Professor
- Portal do Administrador

## Funcionalidades iniciais

### Portal do Aluno
- Registrar-se com e-mail
- Login com e-mail ou matrícula
- Ver notas
- Ver frequência
- Registrar requerimento

### Portal do Professor
- Login com e-mail ou SIAPE
- Registrar notas
- Registrar frequência

### Portal do Administrador
- Login
- Cadastrar/remover alunos e professores
- Ver requerimentos dos alunos

## Decisões técnicas até aqui
- Sistema em C++, rodando em terminal
- Armazenamento inicial em arquivos `.txt`
- Posteriormente, banco de dados poderá ser adicionado
- Organização orientada a objetos
- Login pode ser via e-mail ou matrícula/SIAPE
- Registro obrigatório via e-mail

## Observações
- Aluno pode se registrar; professor só cadastrado pelo administrador
- Administrador vê requerimentos registrados pelos alunos
- O projeto será desenvolvido por etapas com documentação contínua
