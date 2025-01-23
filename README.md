## ALTERAÇÃO MUITO IMPORTANTE
- Pessoal, aquele **minishell**, após avalição de bué de wy aqui, tem bué de bugs que estavam ocultos, porém como não entendia bem o codigo, por ser muito grande e não ser meu, decidi pegar um minishell que trabalhava em casa para fins de aprendizagem sobre minishell com o **Gerson**, otimizei ele e o aprimorei para ser o nosso minishell definitivo. 👌

- Atualmente ele é o minishell_v2.2, depois de alguns testes meus e de outros wys aqui na 42, concluimos que ele **"Tá Pago 👌"**. 

- Por agora é tudo, boa sorte no vosso estudo ai, ele esta bué simples! 👌

# Minishell_das_Tropas

O **minishell** é um projeto da Escola 42 que consiste na implementação de um shell simples em C. O objetivo principal é entender como um shell funciona, lidando com entrada e saída de comandos do usuário, criação e manipulação de processos, além de implementar recursos básicos como pipes, redirecionamento de arquivos e variáveis de ambiente.

## Objetivo

O objetivo do projeto é recriar uma versão simplificada de um shell (como o bash ou zsh) com funcionalidades essenciais, incluindo:
- Leitura de comandos do usuário.
- Execução de programas externos.
- Gerenciamento de processos.
- Manipulação de pipes e redirecionamento de arquivos.
- Suporte a variáveis de ambiente e expansão.

## Funcionalidades Implementadas

O *minishell* inclui as seguintes funcionalidades:

- **Execução de comandos**: O shell executa comandos do usuário, como se fosse um terminal padrão.
- **Redirecionamento de arquivos**: Suporte a redirecionamento de entrada (`<`) e saída (`>`) de arquivos.
- **Pipes**: Suporte a pipes (`|`) para redirecionar a saída de um comando para a entrada de outro.
- **Variáveis de ambiente**: O shell permite definir e modificar variáveis de ambiente usando os comandos `export`, `unset` e `env`.
- **Comandos internos**: Implementação de comandos básicos como `cd`, `exit`, `echo`, `env` e `pwd`.
- **Expansão de variáveis**: Suporte para a expansão de variáveis como `$HOME`, `$PATH` e outras variáveis de ambiente.
- **Tratamento de sinais**: O shell lida corretamente com sinais do sistema, como `SIGINT` e `SIGQUIT`.

## Como Compilar

1. Clone o repositório:
   ```bash
   git clone https://github.com/Kupesa26/Minishell_das_Tropas.git
   cd minishell
   cd minishell_pago
   make
