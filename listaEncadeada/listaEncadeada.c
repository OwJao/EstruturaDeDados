#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int Chave;
    struct Item * Proximo;
} Item;

typedef struct {
    int Tamanho;
    Item * Inicio;
} ListaEncadeada;

ListaEncadeada * criarListaEncadeada();
void inserirItem(ListaEncadeada *L, int Posicao, Item *I);
void imprimirLista(ListaEncadeada *L);
Item *addItem(int Key);

int main(){
    ListaEncadeada *X = criarListaEncadeada();
    if(X != NULL)
        printf("Foi mano!");
        
//    Item *E1 = addItem(6);    inserirItem(X, 0, E1);
//    
//    Item *E2 = addItem(15);    inserirItem(X, 1, E2);
//    
//    Item *E3 = addItem(17); inserirItem(X, 2, E3);
//    
//    Item *E4 = addItem(10);    inserirItem(X, 3, E4);
//    
//    Item *E5 = addItem(13);    inserirItem(X, 4, E5);
//    
//    Item *E6 = addItem(80);    inserirItem(X, 5, E6);
//    
//    Item *E7 = addItem(50);    inserirItem(X, 3, E7);
//        
//    imprimirLista(X);
        
    int Valores[] = {6,15,17,10,13,80,50};
    int Posicoes[] = {0,1,2,3,4,5,6};
    int i;
    for (i = 0; i<7; i++)    
            inserirItem(X, Posicoes[i], addItem(Valores[i]));
            
    removerItem(X, 2);
    imprimirLista(X);
    
        
        
    return 0;
}


ListaEncadeada * criarListaEncadeada(){
    ListaEncadeada * L = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
    if(L == NULL) {
        printf("[ERRO] Nao foi possivel adicionar memoria a lista!");
        return NULL;
    }
    
    L->Tamanho = 0;
    L->Inicio = NULL;
    
    return L;
}

void inserirItem(ListaEncadeada *L, int Posicao, Item *I) {
    if (Posicao < 0 || Posicao > L->Tamanho) {
        printf("[ERRO] Posicao Invalida!");
        return;
    }
    if (Posicao == 0) {
        I->Proximo = L->Inicio;
        L->Inicio = I;
    }
    else {
        Item * e = L->Inicio;
        int i;
        for (i=0; i < Posicao - 1; i++) e = e->Proximo;
        I->Proximo = e->Proximo;
        e->Proximo = I;
    }
    L->Tamanho++;
}

void imprimirLista(ListaEncadeada *L) {
    printf("Infrmacoes da lista armazenada em %p.\n", L);
    printf("Tamanho: %d\n", L->Tamanho);
    int i;
    Item * e = L->Inicio;
    for(i=0; i < L->Tamanho; i++){
        printf("%d ", e->Chave);
        e = e->Proximo;
    }
    printf("\n\n");
}

Item *addItem(int Key){
    Item E = (Item) malloc(sizeof(Item));
    if(E == NULL){
        printf("[ERRO] Nao foi possivel criar memoria para o item!");
        return NULL;
    }
    E->Chave = Key;
    E->Proximo = NULL;
    return E;    
}

void removerItem(ListaEncadeada *L, int Posicao) {
    if(Posicao < 0 || Posicao >=L->Tamanho){
        printf("[ERRO] Posicao Invalida!\n");
        return;
    }
    if(Posicao == 0){
        Item *Temp = L->Inicio;
        L->Inicio = Temp->Proximo;
        free(Temp);
    }
    else {
        Item * e = L->Inicio;
        int i;
        for(i=0; i < Posicao - 1 ; i++) e = e->Proximo;
        Item * Temp = e->Proximo;
        e->Proximo = Temp->Proximo;
        free(Temp);
        L->Tamanho--;
    }
}
