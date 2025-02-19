#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int Numerador;
	int Denominador;
	
}Fracao;


//Protótipos de Funções
Fracao criarFracao(int Num, int Denom);
Fracao simplificarFracao(Fracao F);
Fracao somarFracoes(Fracao F, Fracao G);
Fracao subtrairFracoes(Fracao F, Fracao G);

int main(){
	system("cls");
	
	Fracao F1 = criarFracao(3,7);
	Fracao F2 = criarFracao(16,20);
	Fracao F3 = criarFracao(-20,30);
	Fracao F4 = criarFracao(5,6);
	Fracao F5 = criarFracao(4,9);
	
	//teste 1
	printf("%d/%d", F1.Numerador, F1.Denominador);
	F1 = simplificarFracao(F1);
	printf("\n");
	printf("%d/%d", F1.Numerador, F1.Denominador);
	printf("\n\n");
	
	//teste 2
	printf("%d/%d", F2.Numerador, F2.Denominador);
	F2 = simplificarFracao(F2);
	printf("\n");
	printf("%d/%d", F2.Numerador, F2.Denominador);
	printf("\n\n");
	
	//teste 3
	printf("%d/%d", F3.Numerador, F3.Denominador);
	F3 = simplificarFracao(F3);
	printf("\n");
	printf("%d/%d", F3.Numerador, F3.Denominador);
	printf("\n\n");
	
	
	//teste 4
	Fracao Soma = somarFracoes(F4,F5);
	printf("%d/%d", Soma.Numerador, Soma.Denominador);
	printf("\n\n");
	
	//teste 5
	Fracao Sub = subtrairFracoes(F4,F5);
	printf("%d/%d", Sub.Numerador, Sub.Denominador);
	printf("\n\n");
	
	
	return 0;

}

//Implementações de Funções

Fracao criarFracao(int Num, int Denom){
	
	Fracao F;
	F.Numerador = Num;
	F.Denominador = Denom;
	
	return F;
};

Fracao simplificarFracao(Fracao F){
	int Menor = (F.Numerador < F.Denominador) ? F.Numerador : F.Denominador;
	int MDC = 1;
	
	int i;
	for (i = 1; i<=abs(Menor); i++)
		if(F.Numerador%i == 0 && F.Denominador%i == 0)
			MDC = i;
			
	F.Numerador /= MDC;		
	F.Denominador /= MDC;
	
	return F;
	
};

Fracao somarFracoes(Fracao F, Fracao G){
	Fracao Resultado;
	
	Resultado.Denominador = F.Denominador * G.Denominador;
	Resultado.Numerador = F.Numerador * G.Denominador + F.Denominador * G.Numerador;
	
	Resultado = simplificarFracao(Resultado);
	return Resultado;
};

Fracao subtrairFracoes(Fracao F, Fracao G){
    Fracao Resultado;
    
    Resultado.Denominador = F.Denominador * G.Denominador;
    Resultado.Numerador = F.Numerador * G.Denominador - F.Denominador * G.Numerador;
    
    Resultado = simplificarFracao(Resultado);
    return Resultado;
};

