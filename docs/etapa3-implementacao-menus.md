# Etapa 3 – Implementação inicial (Menus e Utilitários)

## Itens implementados até o momento
- Estrutura de menus para o Portal do Aluno, Professor e Administrador.
- Navegação entre menus com loop e tratamento de opção inválida.
- Função utilitária `ConsoleUtils`:
  - `setColor()` para alterar cor do texto do console.
  - `resetColor()` para restaurar cor padrão.
  - `limparConsole()` para limpar terminal de forma multiplataforma (Windows/Linux/macOS).

## Exemplos das cores usadas
- Azul: títulos e cabeçalhos
- Verde: entradas de opções
- Vermelho: avisos e erros

## Próximos passos
- Criar classes `Usuario`, `Aluno`, `Professor` e `Administrador`.
- Implementar sistema de login e cadastro.
- Persistência em arquivos `.txt` na pasta `/data`.
- Começar validações (regex) para e-mail e matrícula/SIAPE.
- Documentar nova etapa (modelagem OOP).