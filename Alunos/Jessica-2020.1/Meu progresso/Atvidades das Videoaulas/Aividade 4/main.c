#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int NumAlunos = 4;
    const int NumBimestres = 4;

    float MatrizNotas [NumAlunos] [NumBimestres];
    float VetorMedia [NumAlunos] ;
    float media=0;

    for (int l=0; l<NumAlunos;++l){
        printf("Insira todas as notas do aluno %i:\n", l+1);
            for(int c=0  ;  c<NumBimestres  ; ++c){
            scanf("%f",&MatrizNotas[l][c]);
            if(MatrizNotas[l][c]>10 || MatrizNotas[l][c]<0){
                printf("Nota inserida invalida, por favor insira novamente:\n");
                scanf("%f",&MatrizNotas[l][c]);
            }
            media+=MatrizNotas[l][c];
        }
    //Atribuindo as medias ao vetor:
    VetorMedia  [l]  =media/NumBimestres;
    media=0;
    }

    printf("Aprentacao da tabela de notas:\n");
    for (int l=0; l<NumAlunos;++l){
            for(int c=0  ;  c<NumBimestres  ; ++c){
             printf("    %.2f    ", MatrizNotas[l][c]);
            }
        printf("\n");
    }

 //Mostrando as medias de cada aluno:
    for (int j=0;j<NumAlunos;++j){
        printf("A media do aluno %i e %.2f:\n", j+1, VetorMedia[j]);
    }
    return 0;
}
