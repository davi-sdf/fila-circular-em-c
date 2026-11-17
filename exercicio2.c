
#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int senha;
    char nome[50];
} Pessoa;

typedef struct {
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void iniciarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

void mostrarStatus(Fila *fila) {
    printf("\n STATUS DA FILA \n");
    printf("Inicio: %d\n", fila->inicio);
    printf("Fim: %d\n", fila->fim);
    printf("Quantidade: %d\n", fila->quantidade);
}

void inserirPessoa(Fila *fila, int *proximaSenha) {
    if (fila->quantidade == MAX) {
        printf("\n[ERRO] A fila esta cheia! Nao e possivel cadastrar.\n");
        return;
    }

    Pessoa pessoa;

    pessoa.senha = *proximaSenha;

    printf("Digite o nome da pessoa: ");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

    fila->itens[fila->fim] = pessoa;
    fila->fim = (fila->fim + 1) % MAX;
    fila->quantidade++;

    (*proximaSenha)++;

    printf("\n[SUCESSO] %s cadastrado(a) com a senha %d!\n",
           pessoa.nome, pessoa.senha);
}

void chamarProximaPessoa(Fila *fila) {
    if (fila->quantidade == 0) {
        printf("\n[ERRO] A fila esta vazia! Nao ha pessoas para atender.\n");
        return;
    }

    Pessoa pessoa = fila->itens[fila->inicio];

    printf("\n[ATENDIMENTO] Senha: %d | Nome: %s\n",
           pessoa.senha, pessoa.nome);

    fila->inicio = (fila->inicio + 1) % MAX;
    fila->quantidade--;

    printf("[SUCESSO] Pessoa atendida!\n");
}

void visualizarFila(Fila *fila) {
    if (fila->quantidade == 0) {
        printf("\n[ERRO] A fila esta vazia!\n");
        return;
    }

    printf("\n--- FILA DE ESPERA ---\n");

    for (int i = 0; i < fila->quantidade; i++) {
        int posicao = (fila->inicio + i) % MAX;

        printf("Senha: %d | Nome: %s\n",
               fila->itens[posicao].senha,
               fila->itens[posicao].nome);
    }
}

int main() {
    Fila fila;
    int opcao;
    int proximaSenha = 1;

    iniciarFila(&fila);

    do {
        printf("\n SISTEMA DE ATENDIMENTO \n");
        printf("1. Cadastrar pessoa\n");
        printf("2. Chamar proxima pessoa\n");
        printf("3. Visualizar fila de espera\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirPessoa(&fila, &proximaSenha);
                mostrarStatus(&fila);
                break;

            case 2:
                chamarProximaPessoa(&fila);
                mostrarStatus(&fila);
                break;

            case 3:
                visualizarFila(&fila);
                mostrarStatus(&fila);
                break;

            case 4:
                printf("\nEncerrando o sistema de atendimento...\n");
                break;

            default:
                printf("\n[ERRO] Opcao invalida!\n");
                mostrarStatus(&fila);
        }

    } while (opcao != 4);

    return 0;
}
