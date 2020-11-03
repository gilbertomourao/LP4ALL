// caça-palavras: 1 palavra.
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define MAX 50

int main(int argc, char** argv)
{
	char matriz[MAX][MAX],vetor[MAX],inv[MAX],matriz_aux[MAX][MAX],vetor_aux[MAX];
	int p=0,pali=0,m,i,j,k,l,c,cont,qL[MAX]={0},qLI[MAX]={0},qC[MAX]={0},qCI[MAX]={0},qDP[MAX][MAX]={0},qDPI[MAX][MAX]={0},qDS[MAX][MAX]={0},qDSI[MAX][MAX]={0};

	puts("****BEM VINDO AO CACA PALAVRAS!****");
	puts("Qual a ordem do seu caca palavras?");
	printf("Quantidade de linhas: ");
	scanf("%i",&l);
	fflush(stdin);
	printf("Quantidade de colunas: ");
	scanf("%i",&c);
	fflush(stdin);
	
	system("cls");
	putchar('\n');
	printf("                    DIGITE SEU CACA PALAVRAS! (ORDEM [%i]x[%i])\n\n",l,c);
	puts("(OBS: caso digite mais de um elemento em cada ordem, sera considerado, apenas, o primeiro).\n");
	for(i=0; i<l; ++i)
		for(j=0; j<c; ++j){
			printf("Elemento '%ix%i':",i+1,j+1);
			matriz[i][j] = getchar();; // getchar considera apenas o primeiro elemento digitado
			fflush(stdin);
			if(matriz[i][j] == '\n')// caso o usuário digite apenas enter...
				matriz[i][j] = ' ';// ... coloque um espaço vazio.
		}
	system("cls");
	puts("\n");	
	// printando caca-palavras
	puts("MATRIZ DIGITADA:\n");
	for(i=0; i<l; ++i){
		for(j=0; j<c; ++j){
			printf("%c ",matriz[i][j]);
		}
		printf("\n");
	}
	putchar('\n');
	// pegando palavra a ser procurada
	puts("Agora, digite a palavra a ser procurada:");
	gets(vetor);
	fflush(stdin);
	
	if(strlen(vetor) == 0){	
		puts("Invalido! Voce deve digitar algo que contenha caracteres!");
		return 0; // para o programa aqui mesmo, caso o IF seja satisfeito.
	}
	// ignorando SENS.CASE na MATRIZ:
	for(i=0; i<l; ++i)
		for(j=0; j<c; ++j){
			if((matriz[i][j] >= 'A')&&(matriz[i][j]<='Z'))
				matriz_aux[i][j] = matriz[i][j] + 'a' - 'A';
			else
			{
				matriz_aux[i][j] = matriz[i][j];
			} // veja que, agora, a matriz analisada será a matriz_aux.
		}
		
	// ignorando SENS. CASE no VETOR:
	for(i=0; i<strlen(vetor); ++i){
		if((vetor[i]>= 'A')&&(vetor[i]<='Z'))
			vetor_aux[i] = vetor[i] + 'a' - 'A';
		else
		{
			vetor_aux[i] = vetor[i];
		}
	}
	vetor_aux[i] = '\0'; // agora, vetor_aux é uma string.
				
	// invertendo VETOR_AUX (no sens case): para procurar na volta.
	for(i=0; i<strlen(vetor); ++i)
		inv[strlen(vetor)-1-i] = vetor_aux[i];
	inv[i] = '\0';
	// Verificação: é palíndromo?
	for(i=0; i<strlen(vetor_aux); ++i)
		if(vetor_aux[i]==inv[i])
			++p;
	if(p == strlen(vetor_aux))
		pali = 1;	
			
	
	// ANÁLISE NAS LINHAS:
	for(i=0; i<l; ++i)
		for(j=0; j<c; ++j) {
			// indo:
			cont = 0;
			if(matriz_aux[i][j] == vetor_aux[0]) {
				++cont;
				for(k=1;k<strlen(vetor_aux); ++k)
					if(matriz_aux[i][j+k] == vetor_aux[k])
						++cont;
				if(cont == strlen(vetor_aux))
					++qL[i]; // qtde de vezes que VETOR apareceu na linha "i".	
			}
			//voltando:
			if(pali == 0) {
				cont = 0;
				if(matriz_aux[i][j] == inv[0]) {
					++cont;
					for(k=1;k<strlen(inv); ++k)
						if(matriz_aux[i][j+k] == inv[k])
							++cont;
					if(cont == strlen(inv))
						++qLI[i]; // qtde de vezes que VETOR, invertido, apareceu na linha "i".
				}
			}
		}
	//ANÁLISE DAS COLUNAS:
	for(j=0; j<c; ++j)
		for(i=0; i<l; ++i) {
			// indo:
			cont=0;
			if(matriz_aux[i][j] == vetor_aux[0]) {
				++cont;
				for(k=1; k<strlen(vetor_aux); ++k)
					if(matriz_aux[i+k][j] == vetor_aux[k])
						++cont;
				if(cont == strlen(vetor_aux))
					++qC[j]; // qtde de vezes que VETOR apareceu na coluna "j".	
			}
			// voltando:
			if(pali == 0) {
				cont=0;
				if(matriz_aux[i][j] == inv[0]) {
					++cont;
					for(k=1; k<strlen(inv); ++k)
						if(matriz_aux[i+k][j] == inv[k])
					   		++cont;
					if(cont == strlen(inv))
					   	++qCI[j]; // qtde de vezes que VETOR, invertido, apareceu na coluna "j".
	  	  	    }	
			}
		}
		
//ANÁLISE DAS "DIAGONAIS PRINCIPAIS":/

	//-- **Diagonal princ. para baixo**: a diag. princ. está sendo analisada também.

	for(i=0; i<l; ++i){
		j=0; // veja que, para essa analise, "j" deve sempre permanecer = 0(toda vez que mudar a linha).
		for(k=0; ((k+i)<l)&&((k)<c); ++k){ // "k<l" pois a analise é da diag princ para baixo.
			// indo:						// se fosse "k<c", seria acima da diag princ.	
			cont = 0;
			if(matriz_aux[i+k][k] == vetor_aux[0]) {
				++cont;
				for(m=1; ((m+k+i)<l)&&((m+k)<c)&&(m <strlen(vetor_aux)); ++m) // para não extrapolar o numero de L ou C...
					if(matriz_aux[m+k+i][m+k] == vetor_aux[m])
						++cont;
				if(cont == strlen(vetor_aux)) // se for igual, é porque há a palavra naquela diag analisada.
					++qDP[i][j];	// armazena a quantidade de vezes que apareceu em cada diagonal.   	   	
			}
			// voltando:
			if(pali == 0) {
				cont = 0;
				if(matriz_aux[i+k][k] == inv[0]) {
					++cont;
					for(m=1; ((m+k+i)<l)&&((m+k)<c)&&(m <strlen(vetor_aux)); ++m) // para não extrapolar o numero de L ou C...
						if(matriz_aux[m+k+i][m+k] == inv[m])
							++cont;
					if(cont == strlen(inv)) // se for igual, é porque há a palavra naquela diag analisada.
						++qDPI[i][j];		
				} 
			}
  	    }
	}	// VEJA QUE "vetor" E "matriz" ESTÃO INALTERADOS.
	
		// VEJA QUE NÃO É NECESSÁRIO INCLUIR "J" NA CONTAGEM, VISTO QUE SEMPRE PERMANECE ZERO.

// ****Acima da diagonal principal...****
	
	for(j=1; j<c; ++j){ // j=1 para não incluir a diag princ, que ja foi analisada.
		i=0; // veja que, para essa analise, "i" deve sempre permanecer = 0(toda vez que mudar a coluna).
		for(k=0; (k<l)&&((j+k)<c); ++k){ // "k<l" pois a analise é da diag princ para baixo.
			// indo:						// se fosse "k<c", seria acima da diag princ.	
			cont = 0;
			if(matriz_aux[k][j+k] == vetor_aux[0]) {
				++cont;
				for(m=1; ((m+k)<l)&&((m+j+k)<c)&&(m <strlen(vetor_aux)); ++m) // para não extrapolar o numero de L ou C...
					if(matriz_aux[m+k][m+j+k] == vetor_aux[m])
						++cont;
				if(cont == strlen(vetor_aux)) // se for igual, é porque há a palavra naquela diag analisada.
					++qDP[i][j];	// armazena a quantidade de vezes que apareceu em cada diagonal.   	   	
			}
			// voltando:
			if(pali == 0) { // se não for palíndromo...
				cont = 0;
				if(matriz_aux[k][j+k] == inv[0]) {
					++cont;
					for(m=1; ((m+k)<l)&&((m+j+k)<c)&&(m<strlen(inv)); ++m) // para não extrapolar o numero de L ou C...
						if(matriz_aux[m+k][m+j+k] == inv[m])
							++cont;
					if(cont == strlen(inv)) // se for igual, é porque há a palavra naquela diag analisada.
						++qDPI[i][j];		
				} 
			}
  	    }
	}	
	// VEJA QUE NÃO É NECESSÁRIO INCLUIR "I" NA CONTAGEM, VISTO QUE SEMPRE PERMANECE ZERO.

	// VEJA QUE "vetor" E "matriz" ESTÃO INALTERADOS.
	
	
//ANÁLISE DAS "DIAGONAIS SECUNDÁRIAS"/	
	
	// * Análise da diag. sec. para baixo
	for(i=0; i<l; ++i){
		j=c-1; // valor de "J" é o indice dos ultimo termo das linhas.
	   	for(k=0; ((i+k)<l)&&((j-k)>=0); ++k) { // verificar...
			   // indo:
			   cont = 0;
			   if(matriz_aux[i+k][j-k] == vetor_aux[0]) {
			   	    ++ cont; 	
				    for(m=1; ((i+k+m)<l)&&((j-k-m)>=0)&&(m <strlen(vetor_aux)); ++m) // verificar...
					   if(matriz_aux[i+k+m][j-k-m] == vetor_aux[m])
					   	   ++cont;
					if(cont == strlen(vetor_aux))
						++qDS[i][j];	    
	  		}
	  		// voltando:
	  		if(pali == 0) { 
				cont = 0;
				if(matriz_aux[i+k][j-k] == inv[0]) {
			   	    ++ cont; 	
				    for(m=1; ((i+k+m)<l)&&((j-k-m)>=0)&&(m <strlen(inv)); ++m) // verificar...
					   if(matriz_aux[i+k+m][j-k-m] == inv[m])
					   	   ++cont;
					if(cont == strlen(inv))
						++qDSI[i][j];	    
				}	 	  
			}
		}
	}
	
	// análise acima da diagonal sec., sem incluí-la.
	for(j=c-2; j>=0; --j){ // j=c-2 para não incluir a diagonal secundária..
		i=0;
		for(k=0; ((k+i)<l)&&((j-k)>=0); ++k){
			// indo:
			cont = 0;
			if(matriz_aux[i+k][j-k] == vetor_aux[0]) {
				++cont;
				for(m=1; ((m+k+i)<l)&&((j-k-m)>=0)&&(m <strlen(vetor_aux)); ++m)
					if(matriz_aux[m+k+i][j-k-m] == vetor_aux[m])
						++cont;
				if(cont == strlen(vetor_aux))
					++qDS[i][j];	
			}
			// voltando:
			if(pali == 0){ // só analisa voltando se a palavra não for palíndromo...
				cont = 0;
				if(matriz_aux[i+k][j-k] == inv[0]) {
					++cont;
					for(m=1; ((m+k+i)<l)&&((j-k-m)>=0)&&(m <strlen(inv)); ++m)
						if(matriz_aux[m+k+i][j-k-m] == inv[m])
							++cont;
					if(cont == strlen(inv))
						++qDSI[i][j];	
				}
			}
		}
	}
   	

//------------ SEÇÃO PRINTF DO RESULTADO OBTIDO------------------------------------------------------	
		
		for(i=0; i<l; ++i){
			if(qL[i]!=0)
				printf("> %ix, normal, na linha %i.\n",qL[i],i+1);// print QL
			if(qLI[i]!=0) // printf QLI
				printf("> %ix, invertido, na linha %i.\n",qLI[i],i+1);
		}
			
		if(strlen(vetor) > 1){ // só executa essa parte se a palavra tiver mais que uma letra!
			for(i=0; i<l; ++i)	{
				if(qC[i]!=0) // print QC
					printf("> %ix, normal, na coluna %i.\n",qC[i],i+1);
				if(qCI[i]!=0) // printf QCI
					printf("> %ix, invertido, na coluna %i.\n",qCI[i],i+1);
			}
			// diagonais principais
			for(i=0; i<l; ++i)	{ // print QDP
				for(j=0; j<c; ++j)
					if(qDP[i][j]!= 0)
						printf("> %ix, normal, na 'diagonal principal' do elemento [%i][%i].\n",qDP[i][j],i+1,j+1);
				
				for(j=0; j<c; ++j) // print QDPI: só printa se não for palindromo...
					if(qDPI[i][j]!= 0)//...(condição já colocada anteriormente).
						printf("> %ix,invertido, na 'diagonal principal' do elemento [%i][%i].\n",qDPI[i][j],i+1,j+1);	
			}
			
			//diagonais secundárias
			for(i=0; i<l; ++i)	{ // print QDS
				for(j=0; j<c; ++j)
					if(qDS[i][j]!= 0)
						printf("> %ix, normal, na 'diagonal secundaria' do elemento [%i][%i].\n",qDS[i][j],i+1,j+1);
				
				for(j=0; j<c; ++j) // print QDSI: só printa se não for palindromo...
					if(qDSI[i][j]!= 0)//...(condição já colocada anteriormente).
						printf("> %ix,invertido, na 'diagonal secundaria' do elemento [%i][%i].\n",qDSI[i][j],i+1,j+1);	
			}
		}
		
//---------------------------------------------------------------------------------------------------	
	
	return 0;
}