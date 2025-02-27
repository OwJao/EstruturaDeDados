#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int Posicao;
	char Nome[32];
	int Pontos;

}Equipe;



int main() {
	
	FILE *fp;
	
	fp = fopen("tabela.txt", "r");
	
	if(fp == NULL)
		return printf("[ERRO] O ARQUIVO NAO PODE SER ABERTO!");
	

	Equipe A;
	Equipe B;
	
	fscanf(fp, "%d %s %d", &A.Posicao, A.Nome, &A.Pontos);
	printf("O %s esta na %d%c posicao e tem %d pontos!\n", A.Nome, A.Posicao, 167, A.Pontos);

	fscanf(fp, "%d %s %d", &A.Posicao, A.Nome, &A.Pontos);
	printf("O %s esta na %d%c posicao e tem %d pontos!\n", A.Nome, A.Posicao, 167, A.Pontos);
	
	fscanf(fp, "%d %s %d", &A.Posicao, A.Nome, &A.Pontos);
	printf("O %s esta na %d%c posicao e tem %d pontos!\n", A.Nome, A.Posicao, 167, A.Pontos);
	
	fscanf(fp, "%d %s %d", &A.Posicao, A.Nome, &A.Pontos);
	printf("O %s esta na %d%c posicao e tem %d pontos!\n", A.Nome, A.Posicao, 167, A.Pontos);
	
	fscanf(fp, "%d %s %d", &B.Posicao, B.Nome, &B.Pontos);
	printf("O %s esta na %d%c posicao e tem %d pontos!", B.Nome, B.Posicao, 167, B.Pontos); //ERRO pois nao foi declarado no arquivo anteriormente

	fclose(fp);
	
	
	return 0;
}
