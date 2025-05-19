#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 5

int stack[TAMANHO];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == TAMANHO - 1;
}

void push(int data) {
    if (isFull()) {
        printf("Pilha Cheia!\n");
        return;
    }
    top++;
    stack[top] = data;
    printf("Elemento %d empilhado com sucesso.\n", data);
}

int pop() {
    if (isEmpty()) {
        printf("Pilha Vazia!\n");
        return -1; // valor indicativo de erro
    }
    int temp = stack[top];
    top--;
    printf("Elemento %d desempilhado com sucesso.\n", temp);
    return temp;
}

void imprime_pilha() {
    if (isEmpty()) {
        printf("Pilha Vazia.\n");
        return;
    }

    printf("Conteúdo da pilha:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d -> ", stack[i]);
    }
    printf("topo\n");
}

int main() {
    int opcao, valor;

    do {
        printf("\n=== MENU DA PILHA ===\n");
        printf("1. Empilhar (push)\n");
        printf("2. Desempilhar (pop)\n");
        printf("3. Imprimir pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a empilhar: ");
                scanf("%d", &valor);
                push(valor);
                break;
            case 2:
                pop();
                break;
            case 3:
                imprime_pilha();
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

