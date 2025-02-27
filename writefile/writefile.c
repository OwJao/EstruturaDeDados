#include <stdio.h>
#include <stdlib.h>

int main() {
	
	FILE *fp;
	
	fp = fopen("tabela.txt", "w");
	
	if(fp == NULL)
		return printf("[ERRO] O ARQUIVO NAO PODE SER ABERTO!");
	
	int P = 12;
	char Frase[] = "Esta frase sera gravada no arquivo\n";
	
	fprintf(fp, "%d\t%s", P, Frase); //O que sera escrito no arquivo
	
	fclose(fp);
	
	
	return 0;
}
