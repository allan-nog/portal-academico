# Stage 12 - Sistema de Requerimentos 🎓✉️

## ✅ O que foi feito

- Criada a classe `Request` em `src/core/Request.h` e `Request.cpp`, representando um requerimento com:
  - Email do aluno solicitante
  - Mensagem do requerimento
  - Timestamp no formato `YYYY-MM-DD HH:MM:SS`

- Função `createRequest` aprimorada:
  - Pede o requerimento do aluno via terminal.
  - Gera data/hora atual.
  - Grava em `data/requests.txt` no formato:
    ```
    aluno@email.com;Mensagem do requerimento;2025-07-05 12:34:56
    ```

- Função `listRequests` refatorada:
  - Lê linha por linha do arquivo.
  - Cria uma instância `Request` para cada linha.
  - Usa `req.print()` para exibir formatado no terminal.

## 💾 Arquivos alterados / criados

- `src/core/Request.h` e `Request.cpp` criados para encapsular dados de requerimentos.
- `src/utils/UserUtils.cpp` atualizado com a leitura do arquivo e uso do `Request` para impressão.

## 🚀 Como testar

1. Acesse o menu do aluno, faça login e escolha **Registrar requerimento**.
2. Depois, no portal do administrador, acesse **Visualizar requerimentos**.
3. Os dados serão carregados do arquivo e exibidos formatados pela classe `Request`.

---

## 📌 Observações

- O sistema continua usando arquivos `.txt` para persistência, garantindo simplicidade.
- A classe `Request` foi desenhada pensando em evoluir futuramente para:
  - Filtros por data
  - Buscar requerimentos por aluno
  - Exportar relatórios

---

✅ **Stage 12 concluído.**  
Próximas etapas: melhorias visuais, logs, e talvez permissões avançadas. 🚀
