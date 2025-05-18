#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 5

typedef struct {
    int dados[TAMANHO];
    int topo;
} Pilha;

bool isEmpty(Pilha *p){
	return p->topo == -1;
}

bool isFull(Pilha *p){
    return p->topo == TAMANHO - 1;
}

void inicializar(Pilha *p){
    p->topo = -1;
}

void push(Pilha *p, int dado){

	if(p->topo == TAMANHO - 1){
		printf("Pilha Cheia!");
		return;
	}

	p->topo++;
	p->dados[p->topo] = dado;

}

int imprime_pilha(Pilha *p){

	if(isEmpty(p)){
		printf("Pilha Vazia");
		return 0;
	}

	int i;

	for(i = 0; i <= p->topo; i++){
		printf("%d -> ", p->dados[i]);
	}

	printf("topo");
}

int pop(Pilha *p){

	if(isEmpty(p)){
		printf("Pilha Vazia!");
		return 0;
	}

	int temp = p->dados[p->topo];
	p->topo--;
	return temp;

}

void topo(Pilha *p){
	if(isEmpty(p)){
		printf("Pilha Vazia!");
		return;
	}

	printf("\n\nTopo => %d", p->dados[p->topo]);
}

void inverterVetor(){
	int tamanho_vetor = 5;
	int vetor[tamanho_vetor], vetor_invertido[tamanho_vetor];
	Pilha p;
	
	inicializar(&p);
	
	vetor[0] = 1;
	vetor[1] = 2;
	vetor[2] = 3;
	vetor[3] = 4;
	vetor[4] = 5;
	
	for(int i = 0; i < tamanho_vetor; i++){
		push(&p, vetor[i]);
	}	
	
	for(int i = 0; i < tamanho_vetor; i++){
		vetor_invertido[i] = pop(&p);
	}
	
	for(int i = 0; i < tamanho_vetor; i++){
		printf("%d ", vetor[i]);
	}
	
	printf("\n\n");
	
	for(int i = 0; i < tamanho_vetor; i++){
		printf("%d ", vetor_invertido[i]);
		
	}
	
}

void desfazerRefazer(){
    Pilha undo, redo;
    inicializar(&undo);
    inicializar(&redo);

    int opcao, valor;

    while (1){
        printf("\n1 - Fazer operação (inserir número)\n");
        printf("2 - Desfazer (undo)\n");
        printf("3 - Refazer (redo)\n");
        printf("4 - Mostrar pilha de operações\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                if (isFull(&undo)) {
                    printf("Limite de operações atingido!\n");
                    break;
                }
                printf("Digite o número a ser inserido: ");
                scanf("%d", &valor);
                push(&undo, valor);
                inicializar(&redo); // limpa o redo ao fazer nova operação
                break;

            case 2:
                if (!isEmpty(&undo)){
                    valor = pop(&undo);
                    push(&redo, valor);
                    printf("Desfeito: %d\n", valor);
                } else {
                    printf("Nada a desfazer!\n");
                }
                break;

            case 3:
                if (!isEmpty(&redo)){
                    valor = pop(&redo);
                    push(&undo, valor);
                    printf("Refeito: %d\n", valor);
                } else {
                    printf("Nada a refazer!\n");
                }
                break;

            case 4:
                printf("Pilha de operações (UNDO):\n");
                imprime_pilha(&undo);
                printf("Pilha de ações desfeitas (REDO):\n");
                imprime_pilha(&redo);
                break;

            case 0:
                return;

            default:
                printf("Opção inválida!\n");
        }
    }
}

int main(){
	
	
	
	return 0;
}
