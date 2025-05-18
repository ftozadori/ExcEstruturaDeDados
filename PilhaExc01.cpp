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


main(){

    inverterVetor();
    
}





