#include <io.h>
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
	lista -> cabeca = NULL;
}

void inserirInicio(int valor, struct Lista* lista) {
	struct No* novo = (struct No*) malloc(sizeof(struct No));
	novo -> dado = valor;
	novo -> proximo = lista -> inicio;
	lista -> inicio = novo;
}

void inserirPosicao(struct Lista* lista, int valor, int posicao){
	
	if(posicao == 0 || lista -> inicio == NULL){
		inserirInicio(valor, lista);
	}
}

void imprimir(struct Lista *lista) {
	No* temp = lista -> inicio;

	while(temp != NULL) {
		print("%d", temp -> dado);
		temp = temp -> proximo;
	}
	printf("NULL");
}

int main() {
	struct Lista lista1;

	inicializar(&lista1);

	inserirInicio(6, &lista1);
	inserirInicio(5, &lista1);
	inserirInicio(4, &lista1);
	inserirInicio(3, &lista1);
	inserirInicio(2, &lista1);
	
	inserirPosicao(&lista1, 7, 0);

	imprimir(&lista1);

	return 0;
}