#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int ID;
	char Nome[50];
	int Idade;
	
}Pessoa;

int main(){
	
	Pessoa X[3];
	int i=0;
	char Cabecalho[50];
	
	FILE *fp;
	fp = fopen("dados.txt", "r");
	if(fp == NULL)
		return printf("[ERRO]O ARQUIVO NAO PODE SER ABERTO!");
	
	
	fscanf(fp, "%s", Cabecalho);
	printf("%s\n", Cabecalho);
	
	while(fscanf(fp, "%d,%[^,],%d", &X[i].ID, X[i].Nome, &X[i].Idade) == 3) {
		printf("%d\t%s\t%d\n", X[i].ID, X[i].Nome,  X[i].Idade);
		
		i++;
	}
	
	fclose(fp);
	
	return 0;
}
