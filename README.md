Aluno: Davi Leon Carvalho Freitas  

Exercício 1 — Menu de operações

Desenvolvimento de um programa em C que implementa uma fila circular de números inteiros, com capacidade máxima de 5 elementos.

O programa apresenta um menu com as seguintes operações:

1. Inserir um elemento na fila.
2. Remover um elemento da fila.
3. Listar os elementos armazenados.
4. Sair do programa.

A movimentação dos índices é realizada utilizando o operador módulo (%), garantindo o funcionamento circular da fila e respeitando a regra FIFO.

Exercício 2 — Fila circular de atendimento

Desenvolvimento de um sistema de atendimento utilizando uma fila circular implementada com array e struct.

Cada pessoa cadastrada possui:
- Número automático de senha.
- Nome da pessoa.

O sistema permite:
1. Inserir uma pessoa na fila.
2. Chamar a próxima pessoa.
3. Visualizar a fila de espera.
4. Sair do programa.

O programa também apresenta os valores de início, fim e quantidade de elementos após cada operação.

São tratados os casos de fila cheia (overflow) e fila vazia (underflow), impedindo inserções e remoções inválidas.

- Testes realizados

Foram previstos os seguintes testes para verificar o funcionamento da fila circular:

| Teste | Procedimento | Resultado esperado |
|---|---|---|
| 1 | Inserir 5 elementos | Fila preenchida |
| 2 | Inserir mais um elemento | Mensagem de fila cheia |
| 3 | Remover elementos | Elementos removidos na ordem FIFO |
| 4 | Inserir novos elementos | Reaproveitamento das posições liberadas |
| 5 | Remover todos os elementos | Fila vazia |
| 6 | Remover novamente | Mensagem de fila vazia |

- Sequência de teste do Exercício 2

Considerando uma capacidade de 5 pessoas:

1. Cadastrar cinco pessoas: Ana, Bruno, Carlos, Daniela e Eduardo.
2. Tentar cadastrar mais uma pessoa e verificar a mensagem de fila cheia.
3. Chamar duas pessoas, Ana e Bruno.
4. Cadastrar Fernanda e Gabriel, utilizando as posições liberadas.
5. Visualizar a fila e verificar a ordem: Carlos, Daniela, Eduardo, Fernanda e Gabriel.
6. Chamar todas as pessoas.
7. Tentar chamar novamente e verificar a mensagem de fila vazia.

Durante os testes, devem ser conferidos os valores de início, fim e quantidade, inclusive após o reaproveitamento das posições do array.

- Instruções de compilação

### Exercício 1

Compilar:

```bash
gcc -std=c11 -Wall -Wextra exercicio1.c -o exercicio1
```

Executar:

```bash
./exercicio1
```

### Exercício 2

Compilar:

```bash
gcc -std=c11 -Wall -Wextra exercicio2.c -o exercicio2
```

Executar:

```bash
./exercicio2
```

No Windows, utilizando MinGW, os executáveis podem ser iniciados com:

```bash
exercicio1.exe
```

```bash
exercicio2.exe
```

