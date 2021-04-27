//
//  main.c
//  RepoLP02RitaVerissimo
//
//  Created by Rita Verissimo on 28/12/20.
//

#include <stdio.h>
#define MAX 100

int LerTamanho(int *Tamanho);
void LerVetor(int Tamanho, int Vetor[]);
void ModificaVetor(int Tamanho, int Vetor[], int VetorPar[], int VetorImpar[]);
void OrdenaVetorC(int Tamanho, int Vetor[]);
void OrdenaVetorD(int Tamanho, int Vetor[]);
void ColocaVetor(int Tam1,int Tam2, int Vetor[], int VetorPar[],int VetorImpar[]);
void ImprimeVetor(int Tamanho, int Vetor[]);

int main() {
    //Variaveis que serão utilizadas.
    int Tamanho;
    int Vetor[MAX];
    int VetorPar[MAX];
    int VetorImpar[MAX];
    
    //Inicializa o tamanho do vetor que foi digitado pelo usuário.
    Tamanho = LerTamanho(&Tamanho);
    
    //Faz a leitura dos elementos do vetor.
    LerVetor(Tamanho, Vetor);
    
    //Mostra o vetor que foi inicializado pelo usuário.
    printf("\n-----------------Vetor original-----------------\n\n");
    ImprimeVetor(Tamanho, Vetor);
    printf("\n \n");
    printf("--------------------------------------------------\n");
    //Aqui, iremos modificar a funcao de modo a mostrar o vetor com os pares ordenados na parte superior e na inferior o vetor com os impares.
    ModificaVetor(Tamanho, Vetor, VetorPar, VetorImpar);
    
    //Mostra o vetor que foi modificado.
    printf("-----------------Vetor modificado-----------------\n\n");
    ImprimeVetor(Tamanho, Vetor);
    printf("\n \n");
    printf("--------------------------------------------------\n");
    
    return 0;
}
int LerTamanho(int *Tamanho){
    //Aqui, iremos obter o numero de elementos que o vetor tera. Se o usuário entrar com um valor negativo ou maior do que o maximo permitido, iremos pedir para ele inicializar o vetor com um valor válido.
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
   //Essa funcao é responsavel por realizar a leitura dos elementos do vetor.
    
    int i;
    
    for(i=0;i<Tamanho;i++){
        printf("[%d] : ",i);
        scanf("%d",&Vetor[i]);
        fflush(stdin);
    }
}
void ModificaVetor(int Tamanho, int Vetor[], int VetorPar[], int VetorImpar[]){
    //Variaveis que serao utilizadas ao longo da funcao.
    int i,Tam1=0,Tam2=0;
    int j=0;
    int k = 0;
    
    //Aqui, iremos armazenar os numeros pares/impares do vetor em um vetor auxiliar.
    for(i=0;i<Tamanho;i++){
        if(Vetor[i]%2 == 0){
            VetorPar[j] = Vetor[i];
            Tam1++;
            j++;
        }
        if(Vetor[i]%2 != 0){
            VetorImpar[k] = Vetor[i];
            Tam2++;
            k++;
        }
    }
    
    //As funcoes "OrdenaVetor" irão colocar o vetor auxiliar com os elementos pares/impares em ordem crescente.
    OrdenaVetorC(Tam1, VetorPar);
    OrdenaVetorD(Tam2, VetorImpar);
    
    //Aqui, iremos juntar os vetores auxiliares de modo a obtermos apenas 1 vetor, que tem a parte superior formada pelo vetor par e a parte inferior formada pelo vetor impar.
    ColocaVetor(Tam1, Tam2, Vetor, VetorPar, VetorImpar);

}
void OrdenaVetorC(int Tamanho, int Vetor[]){
    //Aqui, temos uma funcao que ira ordenar o vetor em ordem crescente.
    int i,j;
    int aux=0;
    
    /*O processamento se da aqui. Vamos entender o que esta acontecendo:
     1. Os 1 primeiro 'for' servem para percorrer o vetor.
     2. O segundo for, e o que de fato realizara a operacao, inicializamos esse for com uma variavel j, que sempre tera o valor de i+1 . Isso ocorre dado ao fato que eu sempre quero comparar o elemento [i] com o elemento [i+1].
     3.Na 1 iteracao, temos a comperacao do elemento [0] do vetor com o elemento [1]. Se o elemento [0] for menor que o elemento [1] o que acontecera e o seguinte:
        3.1.Uma variavel auxiliar ira receber o valor do elemento [0].
        3.2.A posicao em que se encontrava o elemento [0] ira receber o elemento de menor valor, no caso, o [1].
        3.3.Por fim, o lugar em que se encontrava o elemento [1] ira receber o valor que se encontrava no elemento [0], que esta na variavel auxiliar, ja que, no Passo (2) o local em que se encontrava o elemento [0] foi alterado.
     Isso ira se repetir ao longo de todo o vetor. Ordenando-o.
     */
    for(i=0;i<Tamanho;i++){
        for(j=i+1;j<Tamanho;j++){
            if(Vetor[j] < Vetor[i]){
            aux = Vetor[i];
            Vetor[i] = Vetor[j];
            Vetor[j] = aux;
            }
        }
    }
}
void OrdenaVetorD(int Tamanho, int Vetor[]){
    //Aqui, temos uma funcao que ira ordenar o vetor em ordem decrescente.
    int i,j;
    int aux=0;
    
    for(i=0;i<Tamanho;i++){
        for(j=i+1;j<Tamanho;j++){
            if(Vetor[j] > Vetor[i]){
            aux = Vetor[i];
            Vetor[i] = Vetor[j];
            Vetor[j] = aux;
            }
        }
    }
}

void ColocaVetor(int Tam1,int Tam2, int Vetor[], int VetorPar[],int VetorImpar[]){
    int i,j,k;
    
    //Aqui, iremos colocar no Vetor os elementos pares na parte superior.
    for(i=0;i<Tam1;i++){
        Vetor[i] = VetorPar[i];
    }
    //Aqui, iremos colocar no Vetor os elementos impares na parte inferior.
    for(j=Tam1,k=0;j<Tam1+Tam2;j++,k++)
        Vetor[j] = VetorImpar[k];
    
}
void ImprimeVetor(int Tamanho, int Vetor[]){
    //Funcao para imprimir os elementos do vetor.
    int i;
    
    for(i=0;i<Tamanho;i++){
        printf("[%d]",Vetor[i]);
    }
}
