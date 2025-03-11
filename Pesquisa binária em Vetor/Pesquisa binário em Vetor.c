#include <stdio.h>
#include <stdlib.h>

//Protótipo de funções

	int GetPosicao(int *Vetor, int T, int Chave);
	

//Bloco Principal	
int main() {
	int numeros[] = {14, 29, 37, 11, 43, 25, 19, 32, 16, 22, 40, 13, 28, 35, 10, 45, 20, 38, 17, 24, 30, 41, 15, 27, 33, 18, 26, 39, 12, 21};
	
	int Tamanho = sizeof(numeros) / sizeof(numeros[0]);
	
	int Key = 90;
	
	int posicao = GetPosicao(numeros, Tamanho, Key);
	
	if (posicao != -1) printf("Elemento %d encontrado na posicao: %d\n", Key, posicao);
	
	else printf("Elemento %d nao existe no vetor.\n", Key);
	
	
	
	return 0;
}

//Implementando de funções

int GetPosicao(int *Vetor, int T, int Chave) {
		int i;
		for (i = 0; i < T; i++)
			if (Vetor[i] == Chave)
				return i;
		
		return -1;
	}
