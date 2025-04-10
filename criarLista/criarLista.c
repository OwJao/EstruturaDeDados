#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char chave[15];
} Item;

typedef struct {
	Item *Array;
	int Tamanho;
	int Capacidade;
} Lista;

// Prototipos

Lista * criarLista(int N);
void destruirLista(Lista * L);
void inserirElemento(Lista *L, Item I, int Posicao);
void imprimirLista (Lista *L);

int main(){
	
	Lista *X = criarLista(15);
	if(X != NULL){
		printf("A lista foi criada!\n");
		printf("%d\n", X); //Mostrar endereco de memoria da Lista X
	}
	
	Item E1 = {"marcelo"};
	inserirElemento(X,E1, 0);
	Item E2 = {"jao"};
	inserirElemento(X,E2, 1);
	imprimirLista(X);
	
	
	
	destruirLista(X);
	
	return 0;
}

// Implementacao da Funcao 

Lista * criarLista(int N){
	Lista * L = (Lista *)malloc(sizeof(Lista)); //(Lista *) serve para dividir o valor do retorno do malloc para cada item da struct Lista.
	if (L == NULL){
		printf("[ERRO] Nao foi possivel alocar memoria!");
		return NULL;
	}
	
	L->Array = (Item*)malloc(N*sizeof(Item)); //Utiliza-se "->" para acessar campo de struct quando a variavel for Ponteiro, por exemplo, o "L"
	if (L->Array == NULL){
		printf("[ERRO] Nao foi possivel alocar memoria!");
		free(L);
		return NULL;
	}
	
	L->Tamanho = 0;
	
	L->Capacidade = N;
	
	return L;
}

void destruirLista(Lista * L){
	free(L->Array);
	free(L);
}

void inserirElemento(Lista *L, Item Elem, int Posicao){
	int i;
	if(L->Tamanho == L->Capacidade) {
		printf("[ERRO] A lista esta cheia e nao pode receber mais elementos!");
		return;
	}
	
	if(L->Tamanho == 0){
		L->Array[Posicao] = Elem;
	} else if (Posicao >= 0 && Posicao <= L->Tamanho){
		for(i = L->Tamanho -1; i >= Posicao; i--)
		L->Array[i+1] = L->Array[i];
		L->Array[Posicao] = Elem;
	} else {
		printf("[ERRO]A posicao inserida foi invalida!");
		return;
	}
	
	L->Tamanho++;
}

void imprimirLista (Lista *L){
	int i;
	for(i = 0; i < L->Tamanho; i++) printf("%s \t", L->Array[i].chave);
}

