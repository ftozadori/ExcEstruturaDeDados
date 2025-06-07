#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Define a estrutura de um nó da lista encadeada
typedef struct No {
	int dado;
	struct No* proximo;
};

//Define a estrutura de uma lista encadeada (guarda o inicio)
typedef struct Lista {
	//head, inicio
	struct No* inicio;
};

void inicializar(Lista* lista) {
	lista -> inicio = NULL;
}

void inserirInicio(int valor, struct Lista* lista) {
	struct No* novo = (struct No*) malloc(sizeof(struct No));
	novo -> dado = valor;
	novo -> proximo = lista -> inicio;
	lista -> inicio = novo;
}

void inserirPosicao(struct Lista* lista, int valor, int posicao){
	struct No* temp;
	
	if(posicao == 0 || lista -> inicio == NULL){
		inserirInicio(valor, lista);
		return;
	}
	
	temp = lista -> inicio;
	
	//objetivo do for é encontrar o elemento anterios a posicao
	//que o novo elemento sera inserido

	for(int i = 0; i < posicao -1; i++){
		temp = temp -> proximo;		
	}
	
	struct No* novo = (struct No*) malloc(sizeof(struct No*));
	novo -> dado = valor;
	novo -> proximo = temp -> proximo;
	temp -> proximo = novo;
	
}

void imprimir(struct Lista *lista) {
	No* temp = lista -> inicio;

	while(temp != NULL) {
		printf(" %d ->", temp -> dado);
		temp = temp -> proximo;
	}
	printf("NULL");
}

void inserirFim(struct Lista *lista, int valor){
	struct No* temp;
	temp = lista -> inicio;
	
	if(lista -> inicio == NULL){
		inserirInicio(valor, lista);
		return;
	}
	
	while(temp -> proximo != NULL){
		temp = temp -> proximo;
	}
	
	struct No* novo = (struct No*) malloc(sizeof(struct No*));
	novo -> dado = valor;
	novo -> proximo = NULL;
	temp -> proximo = novo;
}

int main() {
	struct Lista lista1;

	inicializar(&lista1);

	inserirInicio(6, &lista1);
	inserirInicio(5, &lista1);
	inserirInicio(4, &lista1);
	inserirInicio(3, &lista1);
	inserirInicio(2, &lista1);
	
	inserirPosicao(&lista1, 7, 1);

	imprimir(&lista1);

	return 0;
}