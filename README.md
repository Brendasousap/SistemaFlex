# SistemaFlex

**SistemaFlex** é um sistema de gerenciamento flexível desenvolvido como parte da disciplina **Estruturas de Dados 1** do curso de **Engenharia da Computação**.

## Visão Geral

O **SistemaFlex** é um projeto projetado para gerenciar diferentes tipos de itens de forma simples e eficiente. Com um foco em flexibilidade e usabilidade, o sistema pode ser facilmente adaptado para diversas aplicações, como gerenciamento de filmes, produtos, tarefas, entre outros.

## Funcionalidades

- **Autenticação de Usuário**: Permite login com credenciais pré-definidas.
- **Gerenciamento de Itens**:
  - **Cadastro**: Adicione novos itens ao sistema.
  - **Listagem**: Visualize todos os itens cadastrados.
  - **Edição**: Atualize informações de itens existentes.
  - **Exclusão**: Remova itens do sistema.
- **Validação de E-mail**: Verifique e-mails para garantir que sejam válidos e únicos.
- **Menu Interativo**: Navegue facilmente entre as diferentes funcionalidades do sistema.

## Requisitos

- **Compilador C**: GCC ou similar.
- **Padrão C99**: Utilize o padrão C99 para suportar declarações de variáveis dentro de loops `for`.

## Instruções de Compilação

Para compilar o projeto, execute o seguinte comando:

```bash
gcc -std=c99 -o sistema_flex main.c login.c email.c menu.c file_ops.c search.c sort.c
```

## Como Usar

1. **Inicie o Programa**: Execute o programa compilado.
2. **Faça Login**: Insira o nome de usuário e senha quando solicitado. As credenciais pré-definidas são:
   - Usuário: `admin`
   - Senha: `password123`
3. **Acesse o Menu**: Após o login bem-sucedido, você terá acesso ao menu principal com as seguintes opções:
   - **1. Cadastrar Item**: Adicione novos itens.
   - **2. Listar Itens**: Veja todos os itens cadastrados.
   - **3. Editar Item**: Modifique itens existentes.
   - **4. Excluir Item**: Remova itens.
   - **5. Sair**: Encerre o programa.
4. **Validação de E-mail**: Adicione e-mails e verifique se são válidos e únicos.
