#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct Item {
//    char Titulo[50];
//    char Autor[100];
//    int Ano;
//    struct Item * Proximo;
//    struct Item * Anterior;
//} Item;

typedef struct Tarefa {
	int Id;
	char Descricao[100];
	int Prioridade; // 1 = alta, 2 = m�dia, 3 = baixa
	struct Tarefa *Anterior;
	struct Tarefa *Proximo;
} Tarefa;

typedef struct Lista {
    Tarefa * Inicio;
    Tarefa * Final;
    int Tamanho;
} Lista;

Tarefa * criarTarefa(int Id, char * Descricao, int Prioridade);
Lista *criarLista();

void navegarDoInicio(Lista * L);
void inserirTarefa(Lista * L, Tarefa * I);
void excluirTarefa(Lista * L, int Posicao);
void inverter(Lista * L, int id1, int id2);

int main() {

    Lista * Tarefas = criarLista();
    
    Tarefa * A = criarTarefa(1, "Skyrim.exe", 1);
    inserirTarefa(Tarefas, A);
    
    Tarefa * B = criarTarefa(2, "GtaVI.exe", 1);
    inserirTarefa(Tarefas, B);
    
    Tarefa * C = criarTarefa(3, "Terraria.exe", 1);
    inserirTarefa(Tarefas, C);
    
    Tarefa * D = criarTarefa(4, "Discord.exe", 2);
    inserirTarefa(Tarefas, D);
    
    Tarefa * E = criarTarefa(5, "VSCode.exe", 3);
    inserirTarefa(Tarefas, E);
    
    Tarefa * F = criarTarefa(6, "DevC++.exe", 3);
    inserirTarefa(Tarefas, F);
//    excluirTarefa(Tarefas, 5);
    
    navegarDoInicio(Tarefas);
    
    printf("=============================================\n\n");
    
    inverter(Tarefas, 2, 5);
    
    
//    Item * D = criarItem("Aquarela", "Toquinho", 1983);
//    inserirItem(PlayList, 0, D);
//    Item * E = criarItem("Romaria", "Renato Teixeira", 1978);
//    inserirItem(PlayList, 1, E);
//    Item * F = criarItem("Eu nasci há dez mil anos atrás", "Raul Seixas", 1976);
//    inserirItem(PlayList, 2, F);
//    Item * G = criarItem("Cálice", "Chico Buarque e Gilberto Gil", 1978);
//    inserirItem(PlayList, 3, G);
//    Item * H = criarItem("Tempo Perdido", "CRenato Russo", 1986);
//    inserirItem(PlayList, 4, H);

    
}

void inverter(Lista * L, int id1, int id2){
	Tarefa * T1 = L->Inicio;
	Tarefa * T2 = L->Inicio;
	
	Lista * LT = criarLista();
	
	while(T1->Proximo->Id != id1) T1 = T1->Proximo;
	while(T2->Id != id2) T2 = T2->Proximo;
	
	
	Tarefa * temp = T2;
	while(temp->Id != T1->Id){
		Tarefa * temp2 = criarTarefa(temp->Id, temp->Descricao, temp->Prioridade);
		inserirTarefa(LT, temp2);
		temp = temp->Anterior;
	}
	
	// Atualiza a lista principal
	T2 = T2->Proximo;
	T1->Proximo = LT->Inicio;
	LT->Inicio->Anterior = T1;
	
	Tarefa * temp3 = LT->Inicio;
	while(temp3->Proximo != NULL) temp3 = temp3->Proximo;
	
	temp3->Proximo = T2;
	if (T2 != NULL) T2->Anterior = temp3;
	
	// Atualiza final se necess�rio
	if (T2 == NULL) L->Final = temp3;
	
	// Agora sim, imprime a lista principal com a altera��o:
	navegarDoInicio(L);
}

Tarefa * criarTarefa(int Id, char * Descricao, int Prioridade) {
    Tarefa * X = (Tarefa *) malloc (sizeof(Tarefa));
    if (X == NULL) {
        printf("ERRO: não foi possível alocar memória para a música!\n");
        return NULL;
    }
    strcpy(X->Descricao, Descricao);
    X->Id = Id;
    X->Prioridade = Prioridade;
    X->Anterior = NULL;
    X->Proximo = NULL;
    return X;    
}

Lista *criarLista(){
    
    Lista * L = (Lista *) malloc(sizeof(Lista));
    if (L == NULL) {
        printf("ERRO: não foi possível alocar memória para a lista!\n");
        return NULL;
    }
    L->Tamanho = 0;
    L->Inicio = NULL;
    L->Final = NULL;
    return L;

}

void navegarDoInicio(Lista * L) {
    Tarefa * Atual = L->Inicio;
    int i = 1;
    while( Atual != NULL ) {
        printf("[%d] %s\n", i++, Atual->Descricao);
        Atual = Atual->Proximo;
    }
    printf("\n");
}

//void navegarDoFinal(Lista * L){
//    Item * Atual = L->Final;
//    int i;
//    for(i = 0; i < L->Tamanho; i++) {
//        printf("[%d] %s\n", i, Atual->Titulo);
//        Atual = Atual->Anterior;
//    }
//    printf("\n");
//}

void inserirTarefa(Lista * L, Tarefa * I){

    Tarefa * Atual = L->Inicio;

    if (L->Inicio == NULL){
    	L->Inicio = I;
	} else {
        while(Atual->Proximo != NULL) {
        	Atual = Atual->Proximo;
		}
		Atual->Proximo = I;
		I->Anterior = Atual;
    	}

    L->Tamanho++;

}


void excluirTarefa(Lista * L, int Posicao) {
    if(Posicao <= 0 || Posicao > L->Tamanho) return;
    Tarefa * Atual = L->Inicio;

    if (Posicao == 1) {
        L->Inicio = Atual->Proximo;
        if (L->Inicio) Atual->Proximo->Anterior = NULL;
    }
    else {
    	int i;
        for(i = 1; i < Posicao; i++) Atual = Atual->Proximo;
        if (Atual->Anterior != NULL) Atual->Anterior->Proximo = Atual->Proximo;
        if (Atual->Proximo != NULL) Atual->Proximo->Anterior = Atual->Anterior;
        if (Posicao == L->Tamanho) L->Final = Atual->Proximo;
    }

    free(Atual);
    L->Tamanho--;

}
