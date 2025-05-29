#include <iostream>
#include <stdlib.h>
#include <stdbool.h>


typedef struct No{
	int dado;
	No *proximo;
}No;

typedef struct Fila{
	struct No *inicio;
	struct No *fim;
}Fila;

void inicializar(Fila *fila){
	fila -> inicio = NULL;
	fila -> fim = NULL;
}

bool estaVazia(Fila *fila){
	return (fila -> inicio == NULL && fila -> fim == NULL);
	return true;
}

void enfileirar(Fila *fila, int valor){
	No* novo = (No*) malloc(sizeof(No));
	novo -> dado = valor;
	
	if(estaVazia(fila)){
		fila -> inicio = novo;
	}else {
		fila -> fim -> proximo = novo;
		fila -> fim = novo;
	}
	
	fila -> fim = novo;
	fila -> fim -> proximo = NULL;
}

void imprimir(Fila *fila){
	No *temp = fila -> inicio;
	
	while(temp != NULL){
		printf("%d ", temp -> dado);
		temp = temp -> proximo;
	}
}

int main(int argc, char** argv){
	Fila fila1;
	
	inicializar(&fila1);
	
	enfileirar(&fila1, 12);
	enfileirar(&fila1, 14);
	enfileirar(&fila1, 16);
	
	imprimir(&fila1);
	
	return 0;
}
