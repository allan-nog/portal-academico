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
- Sistema implementado em C++ (rodando via terminal)
- Armazenamento inicial em arquivos `.txt` na pasta `/data`
- Organização orientada a objetos planejada
- Login via e-mail ou matrícula/SIAPE
- Registro inicial obrigatório por e-mail
- Posteriormente o sistema poderá migrar para uso de banco de dados.

## Observações gerais
- Aluno registra-se sozinho; professor é cadastrado pelo administrador.
- Administrador possui visão dos requerimentos dos alunos.
- Projeto será desenvolvido por etapas com documentação incremental.
