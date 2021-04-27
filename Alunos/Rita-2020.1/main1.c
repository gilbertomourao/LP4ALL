//
//  main.c
//  RepoLP01RitaVerissimo
//
//  Created by Rita Verissimo on 28/12/20.
//

#include <stdio.h>
#define MAX 100

int LerTamanho(int *Tamanho);
void LerVetor(int Tamanho, int Vetor[]);
void VerificarSegmento(int Tamanho, int Vetor[], int VetorAux[]);
void Imprimir(int Tamanho, int VetorAux[], int Vetor[], int cont, int inicio);

int main(){
    int Vetor[MAX];
    int VetorAux[MAX];
    int Tamanho;
    
    //Aqui, iremos atribuir a variavel tamanho o tamanho que foi inicializado pelo usuário.
    Tamanho = LerTamanho(&Tamanho);
    
    //Aqui, iremos inicializar o vetor com os valores inicializados pelo usuário.
    LerVetor(Tamanho, Vetor);
    
    //Aqui, temos o processamento da questao em si, em que iremos verificar qual o maior segmento crescente.
    VerificarSegmento(Tamanho, Vetor, VetorAux);
    
    return 0;
}
int LerTamanho(int *Tamanho){
    //Nessa funcao, iremos obter do usuário o numero de elementos que ele deseja para o vetor.
    do{
        printf("Entre com o numero de elementos do vetor: ");
        scanf("%d",Tamanho);
        fflush(stdin);
        if (*Tamanho <= 0 || *Tamanho>100) {
            printf("O tamanho inserido e invalido... Por favor, entre com um valor valido!!");
        }
    }while(*Tamanho <= 0 || *Tamanho>100);
    return *Tamanho;
}
void LerVetor(int Tamanho, int Vetor[]){
    //Funcao para ler os elementos inseridos pelo usuário.
    int i;
    
    for(i=0;i<Tamanho;i++){
        printf("[%d] : ",i);
        scanf("%d",&Vetor[i]);
        fflush(stdin);
    }
}
void VerificarSegmento(int Tamanho, int Vetor[], int VetorAux[]){

    int i,j;
    int cont=0;
    int inicio = 0;
    int marcador = 0;
    
    //Aqui, temos uma funcao que ira percorrer o vetor e comparar sempre o seu elemento atual do "for" com o elemento subsequente. Daí, temos o "if", em que sempre que o elemento subsequente for maior que o anterior, o cont é incrementado. Quando isso nao acontece, vamos para o "else", em que temos uma variavel auxiliar, que no caso, é o "marcador" que vai receber o valor de cont e, isso vai servir para caso eu tenha, por exemplo, um segmento de 3 e posteriormente um de 4, o cont vai ser maior que o "marcador" atual e o marcador vai receber o valor de cont, atualizando o maior segmento.
    for(i=0;i<=Tamanho;i++){
        j=i+1;
        if (Vetor[j] > Vetor[i]) {
            cont++;
        }else {
            if(cont > marcador){
                marcador = cont;
                inicio = i - marcador;
                //printf("\nIn : %d \n",inicio);
            }
            
            cont = 0;
        }
        
    }
    Imprimir(Tamanho, VetorAux, Vetor, marcador, inicio);
}
void Imprimir(int Tamanho, int VetorAux[], int Vetor[], int cont, int inicio){
    int i;
    //Aqui, temos a funcao para imprimir o vetor, dividida em 2 casos:
        //1. O maior segmento crescente do vetor é 1.
        //Qualquer caso que o segmento seja maior que 1.
    if(cont == 0){
        printf("O vetor com maior segmento e:\n");
        for(i=0;i<Tamanho;i++){
            printf("[%d]",Vetor[i]);
        }
        printf("\nO maior segmento tem tamanho: 1 \n");
        
    }
    if(cont > 1){
        printf("O vetor com maior segmento e:\n");
        for(i=inicio;i<inicio + cont + 1;i++){
            printf("[%d]",Vetor[i]);
        }
        printf("\nO maior segmento tem tamanho %d. \n",cont+1);
    }
    
}
