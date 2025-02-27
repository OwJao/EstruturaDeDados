#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	
	fp = fopen("arquivo.txt", "w"); // Primeiro vem o nome do arquivo, depois o W abre para escrita
	
	if(fp == NULL){
		return printf("[ERRO] O ARQUIVO NAO PODE SER ABERTO");
	}
	
	fclose(fp);	
	
	
	
	
	return 0;
}
