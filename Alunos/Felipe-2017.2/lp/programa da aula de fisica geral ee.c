/*
UFMA-ENGENHARIA EL�TRICA
MAT�RIA: F�sica Geral - EE
ALUNO:Felipe Alencar Araujo
PROFESSOR: Humberto 
PROGRAMA: M�todo da bissec��p
ANO:2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funcoes que serao usadas: "f" e "bissec";
float f(float x)
{
    float y;
    y = 3.73*(pow(2.71,x/4))-4*x; //(e = 2.71);
    return y;
}

float bissec(float a, float b, float erro) // Recebendo intervalo e a precis�o;
{
    // Ti = Valor de X para cada interacao;
    // f(a) = Funcao no ponto A;
    // f(b) = Funcao no ponto B;
    // F(Ti) = Funcao no ponto Ti;
    float Ti,fa,fb,FTi,i=0;

    fa=f(a);
    fb=f(b);

    while(fabs(b-a)>erro){ // Intera��es (fabs(b-a) = M�dulo de b-a);
        Ti=(a+b)/2;
        FTi=f(Ti);
        if(fa*FTi<0){

            b=Ti;
            fb=FTi;
        }
        else{
            a=Ti;
            fa=FTi;
        }
        ++i; // Cont de Intera��es;
    }
    printf("\n>> N. Interacoes = %f",i);

    Ti=(a+b)/2;
    return Ti;
}



main()
{
    float x, y, w, erro;

    printf(" Bisseccao \n\n");
    printf(" Entre com os intervalos [a,b]:\n");

    printf("\n~> x = "); // Leitura dos intervalos [a,b]
    scanf("%f",&x);

    printf("~> y = ");
    scanf("%f",&y);

    printf("\n~> Precisao desejada = "); // Leitura do ERRO/PRECISAO
    scanf("%f",&erro);

    if(f(x)*f(y)>0)
    {
        printf("O intervalo inserido nao obedece as condicoes do Teorema.\n\n"); // Teste Intervalo Pelo Teorema De Boolzano
        printf("\n> Tente com um novo intervalo.\n");

        printf("\n~> x = ");
        scanf("%f",&x);

        printf("~> y = ");
        scanf("%f",&y);
    }
    printf("\n::::: Analise :::::");
    w=bissec(x,y,erro);

    printf("\n>> No Intervalo [%.1f , %.1f]:",x,y);
    printf("\n>> Raiz encontrada = %0.9f\n\n",w); // Impress�o da raiz aproximada da funcao no intervalo [a,b]

	return 0;
}


