#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int N = 10; //tamanho do vetor a ser criado
	int i;
	int *V = malloc(N*sizeof(int)); //caso dê erro colocar '(int *)' antes do malloc
	
	srand(time(NULL)); //baseia-se na hora do sistema
	
	for (i=0; i<N; i++){
		V[i] = rand();
	}
	for(i=0; i<N; i++){
		printf("%d\t", V[i]);
	}
	
	
	
	return 0;
}
