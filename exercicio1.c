
#include <stdio.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void iniciarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

void inserir(Fila *fila, int valor) {
    if (fila->quantidade == MAX) {
        printf("\n[ERRO] A fila esta cheia!\n");
        return;
    }

    fila->itens[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % MAX;
    fila->quantidade++;

    printf("\n[SUCESSO] Elemento %d inserido na fila!\n", valor);
}

void remover(Fila *fila) {
    if (fila->quantidade == 0) {
        printf("\n[ERRO] A fila esta vazia!\n");
        return;
    }

    int valor = fila->itens[fila->inicio];

    fila->inicio = (fila->inicio + 1) % MAX;
    fila->quantidade--;

    printf("\n[SUCESSO] Elemento %d removido da fila!\n", valor);
}

void listar(Fila *fila) {
    if (fila->quantidade == 0) {
        printf("\n[ERRO] A fila esta vazia!\n");
        return;
    }

    printf("\nElementos armazenados na fila:\n");

    for (int i = 0; i < fila->quantidade; i++) {
        int posicao = (fila->inicio + i) % MAX;
        printf("%d ", fila->itens[posicao]);
    }

    printf("\n");
}

int main() {
    Fila fila;
    int opcao, valor;

    iniciarFila(&fila);

    do {
        printf("\n FILA CIRCULAR \n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Listar elementos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserir(&fila, valor);
                break;

            case 2:
                remover(&fila);
                break;

            case 3:
                listar(&fila);
                break;

            case 4:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\n[ERRO] Opcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}
