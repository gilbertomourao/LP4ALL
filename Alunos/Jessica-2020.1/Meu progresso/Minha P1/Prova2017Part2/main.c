#include <stdio.h>
#include <stdlib.h>

int main()
{
    char frase[100], palavra[100], substituto[100], resposta[500];
    char palavraM[100], fraseM[100], invertida[100];
    int tam1=0, tam2=0, tam3=0;
	int i,j,k=0;
	int i_aux;
	int especial=0;
	int alarme_falso=0;
    int ocorrencia=0;
    int confirma=0;

	printf("Insira a frase: ");
	gets(frase);
	printf("Insira a palavra: ");
    gets(palavra);
    printf("Insira a o item de substituicao: ");
    gets(substituto);

    /*Descobrir o tamanho das strings de entrada*/
    while(frase[tam1]!='\0') ++tam1;//Tamanho da frase

    while(palavra[tam2]!='\0') ++tam2;//Tamanho da palavra

    /*Desconsiderando Case-sensitive*/
    for(i=0;frase[i]!='\0';++i){ //Passando frase para auxiliar
        fraseM[i]=frase[i];
     }
    fraseM[i]='\0';
     for(i=0;palavra[i]!='\0';++i){ //Passando palavra para auxiliar
        palavraM[i]=palavra[i];
     }
    palavraM[i]='\0';

    for(j=0;fraseM[j]!='\0';++j){ //Transforma todas as letras em maiusculas
          if (fraseM[j] >= 'a' &&  fraseM[j] <= 'z')
             fraseM[j] = fraseM[j] - 'a' + 'A';
    }
    for(j=0;palavraM[j]!='\0';++j){ //Transforma todas as letras em maiusculas
          if (palavraM[j] >= 'a' &&  palavraM[j] <= 'z')
             palavraM[j] = palavraM[j] - 'a' + 'A';
    }

    /*Verifica se o primeiro caractere de palavra é igual ao  ultimo*/
    if(palavraM[0]==palavraM[tam2-1])
        especial=1;

    /*Verificar se a palavra é maior que a frase*/
    if( tam2 > tam1 ){
       printf("\n\nSituacao invalida, pois a palavra a ser substituida eh maior que a propria frase\n\n");
       return 0;
    }

    /*Localizando a palavra na frase*/
    for(i=0; fraseM[i]!='\0'; i++){ //Percorre toda string frase - laço principal

        if(fraseM[i]==palavraM[0]){ //Indica quando o primeiro caractere da palavra é encontrado na frase
            confirma=1; //Diz se a palavra está realmente contida na frase
            for(j=0, i_aux=i; palavraM[j]!='\0' && fraseM[i_aux]!='\0';j++, i_aux++){ //Confirma a exist. da palavra na frase
                if(palavraM[j]!=fraseM[i_aux]){
                    confirma=0;
                    break;
                }
            }

            if(confirma && palavraM[j]=='\0'){ //Se palavra for achada na frase
                ++ocorrencia;
                for(j=0; substituto[j]!='\0'; j++){
                    resposta[k++]=substituto[j];
                }
                if(especial){
                    i=i_aux - 2;
                    alarme_falso=1;
                }else{
                    i=i_aux - 1;
                }
            } else{
                if(alarme_falso && (palavraM[j]!=fraseM[i_aux]) ){
                    ++i;
                    resposta[k++]=frase[i];
                    alarme_falso=0;
                } else {
                    resposta[k++]=frase[i];
                }
            }
        }else{
                resposta[k++]=frase[i];
        }
    }
    resposta[k]='\0';

	if(ocorrencia>0){
        printf("\n\n--------------------------NOVA FRASE-------------------------------");
        printf("\n\n%s\n\n", resposta);
	}

    return 0;
}
