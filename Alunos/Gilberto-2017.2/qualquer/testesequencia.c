#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_QUEBRA 10
#define NUM_ELE 6
#define NUM_SEQ 3

int main(){

	int venceu = 0,quebra = 0;
	int numero,seq[NUM_SEQ];
	unsigned long int jogou = 0;
	
	int j;
	for (j = 0;j < NUM_SEQ;j++)
		seq[j] = j+1;
	
	
	srand(time(NULL));
	while (jogou < 1000000){ /*Joga Um milhão de vezes*/
			numero = 1+rand()%NUM_ELE;
			if (numero == seq[0]){
				j = 0;
				while (numero == seq[j]){
					j++;
					if (j == NUM_SEQ)
						break;
					numero = 1+rand()%NUM_ELE;
				}
				if (j < NUM_SEQ){
					quebra++;
					
				}
				else{ /*Se j for igual ao número de termos na sequência, venceu o jogo*/
					venceu++; 
					jogou++;
					quebra = 0;
				}
			}
			if (quebra == NUM_QUEBRA){ /*Se atingir a quantidade de quebras para perder*/
				jogou++;
				quebra = 0;
			}	
	}
	
	printf("Probabilidade: %.6f", (double)venceu/jogou);
	/*P = 1 - [1-(NUM_ELE)^(1-NUM_SEQ)]^NUM_QUEBRA*/
	
	return 0;	
}