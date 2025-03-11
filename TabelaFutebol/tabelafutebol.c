#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int Posicao;
	char Estado[32];
	char Time[32];
	int Pontos;
	int J; // N° de jogos
	int V; // N° de vitórias
	int E; // N° de empates
	int D; // N° de derrotas
	int GP; // Gols marcados
	int GC; // Gols sofridos
	int SD; // Saldo de gols
	float Aproveitamento; // % de pontos conquistados em relacao ao total de pontos disputados
} Equipe;


//Protótipo de funções
Equipe *LerDados(const char *NomeArquivo);

//Bloco Principal
int main(){
	
	Equipe *Dados = LerDados("teste.txt");
	
	int i;
	
	for(i = 0; i < 20; i++){
		printf("%s \t %d \t %.0f%%\n", Dados[i].Time, Dados[i].GP, Dados[i].Aproveitamento);
	};
	
	
	return 0;
}

//Implementando funções

Equipe *LerDados(const char *NomeArquivo){
	FILE *fp = fopen(NomeArquivo, "r");
	
	if(fp == NULL) {
		printf("[ERRO]: O arquivo nao pode ser aberto!");
		exit(1);
	}
	
	
	
	Equipe *X = malloc(20 * sizeof(Equipe));
	if(X == NULL){
		printf("[ERRO] Nao foi possivel alocar memoria!");
		exit(1);
	}
	
	
	int N = 0; //Indice para o vetor de equipes
	char Cabecalho[100]; //Para guardar a primeira linha que nao sera usada
	
	fscanf(fp, "%[^\n]", Cabecalho);
	printf("%s\n", Cabecalho);
	
	while(fscanf(fp, "%d;%[^;];%[^;];%d;%d;%d;%d;%d;%d;%d;%d", &X[N].Posicao, X[N].Estado, X[N].Time, &X[N].Pontos, &X[N].J, &X[N].V, &X[N].E, &X[N].D, &X[N].GP, &X[N].GC, &X[N].SD) == 11){
		X[N].Aproveitamento = 100 * (float) X[N].Pontos / (float) (3 * X[N].J);
		N++;
	};
	
	fclose(fp);
	
	return X;
}



