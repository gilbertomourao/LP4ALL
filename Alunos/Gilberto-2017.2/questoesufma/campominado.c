/*Campo Minado*/

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define MAX 30

void instrucoes ();
int contaminas (char *,int *,int *,int *);
void mostra (char *,int *,int *,int *);
void geracampo (char *,char *,int *,int *,int *);
void geramina (char *, int *,int *,int *,int *,int,int);
int contabomba (char *,char *,int *,int *,int,int);
void revela (char *, char *,int *,int *,int,int,int *);
int contaast (char *,int *,int *,int,int);
void expande (char *,char *,int *,int *,int *);
int revelado (char *,int *,int *);
int existe (char *,int *,int *,int,int);
void abre (char *,char *,int *,int *,int *);
void leitura (char *);
void joga (char *,char *,int *,int *,int *,int *);

int main(){
	
	char jogo[MAX][MAX], bombas[MAX][MAX];
	int L,C,termina,dificuldade;
		
	puts("Selecione uma dificuldade: ");
	puts("[3] para dificil");
	puts("[2] para medio");
	puts("[1] para facil");
	printf("Dificuldade: "); scanf("%d", &dificuldade); while (getchar()!='\n');
	
	while (dificuldade < 1 || dificuldade > 3){
		   printf("Dificuldade INVALIDA!!! Tente novamente... "); 
		   scanf("%d", &dificuldade); while (getchar()!='\n');
	}
	
	geracampo(jogo[0],bombas[0],&L,&C,&dificuldade);

	joga(jogo[0],bombas[0],&L,&C,&termina,&dificuldade);
	
	system("pause");
	
	return 0;	
}

/************************************************************
 * Todas as funções logo abaixo.
 ************************************************************/
 
void instrucoes (){
	printf("Para escolher uma posicao, digite as letras correspondentes as coordenadas do ponto.\n\n");
	printf("Exemplo: Linha 'a' Coluna 'a'\n\n");
	printf("Basta digitar 'aa' (sem aspas) na area de digitacao.\n\n");
	printf("**********COMO INSERIR BANDEIRAS**********\n\n");
	printf("Para inserir uma bandeira (flag) numa posicao, basta digitar F antes da posicao visada.\n\n");
	printf("Exemplo: Bandeira na posicao 'bf'\n\n");
	printf("Digite 'Fbf' (sem aspas) e sera inserida uma bandeira (F) na posicao 'bf'.\n\n");
	printf("Para remover uma bandeira inserida, basta seguir os passos anteriores numa posicao onde ja exista bandeira.\n\n");
	printf("Exemplo: Remover a bandeira na posicao 'bf'\n\n");
	printf("Digite 'Fbf'. Se esta posicao ja estiver com uma bandeira, ela sera removida.\n\n");
	printf("**********O CHUTE**********\n\n");
	printf("Na dificuldade dificil[3], e possivel 'Chutar' se o jogador tiver chutes disponiveis. ");
	printf("Assim que liberar 20%% do campo livre, o jogador recebera 1 chute. Quando liberar 80%% do campo, recebera mais 1.\n\n");
	printf("*O chute abre uma posicao aleatoria proxima a uma ja aberta, revelando quantas bombas existem ao seu redor. ");
	printf("Para chutar, basta digitar 'C' (sem aspas) na area de digitacao.\n\n");
	printf("O chute ajuda o jogador em situacoes onde nao e possivel determinar com certeza se uma posicao tem ou nao uma bomba.\n");
} 
 
int contaminas (char *jogo,int *L,int *C,int *termina){
	
	int i,j;
	unsigned int minas = (*L)*(*C)-*termina;
	
	for (i = 0;i < *L;i++)
		for (j = 0;j < *C;j++)
			if (*(jogo + i*MAX + j) == 'F' && minas > 0)
				minas--;
			
	return minas;
}

void mostra (char *jogo,int *L,int *C,int *termina){

	int i,j,k;
	
	puts("*****CAMPO MINADO*****");	
	putchar('\n');
	
	for (i = 0;i < *L;i++){
		if (i == 0){
			for (k = 0;k <= *C;k++)
				if (k == 0) printf(" ");
				else printf(" %c ",(char)k+'a'-1);
			putchar('\n');
		}
		printf("%c",(char)i+'a');	
		for (j = 0;j < *C;j++)
			printf(" %c ", *(jogo + i*MAX + j));
		printf("%c ",(char)i+'a');
		putchar('\n');
	}
	for (k = 0;k <= *C;k++)
		if (k == 0) printf(" ");
		else printf(" %c ",(char)k+'a'-1);
	puts("\n");
}

void geracampo (char *joga,char *bombas,int *L,int *C,int *dificuldade){
	
	int i,j;
	
	if (*dificuldade == 3){
		*L = 16; *C = 26;
	}
	else if (*dificuldade == 2){
		*L = *C = 16;
	}
	else {
		*L = *C = 9;
	}
	
	for (i = 0;i < *L;i++)
		for (j = 0;j < *C;j++){
			*(joga + i*MAX + j) = *(bombas + i*MAX + j) = '*';
		}
	
}

void geramina (char *bombas,int *L,int *C,int *termina,int *dificuldade,int linha,int coluna){
	
	int i,l,c;
	
	srand(time(NULL));
	
	if (*dificuldade == 3){
		*termina = ((*L)*(*C) - 99);
		for (i = 0;i < 99;i++){
			l = rand()%(*L-1);
			c = rand()%(*C-1);
			if (*(bombas + l*MAX + c) != 1 && (l != linha || c != coluna))
				*(bombas + l*MAX + c) = 1;
			else 
				i--;
		}	
	}
	else if (*dificuldade == 2){	
		*termina = ((*L)*(*C) - 40);
		for (i = 0;i < 40;i++){
			l = rand()%(*L-1);
			c = rand()%(*C-1);
			if (*(bombas + l*MAX + c) != 1 && (l != linha || c != coluna))
				*(bombas + l*MAX + c) = 1;
			else 
				i--;
		}
	}
	else {
		*termina = ((*L)*(*C) - 10);
		for (i = 0;i < 10;i++){
			l = rand()%(*L-1);
			c = rand()%(*C-1);
			if (*(bombas + l*MAX + c) != 1 && (l != linha || c != coluna))
				*(bombas + l*MAX + c) = 1;
			else 
				i--;
		}
			
	}
			
	system("cls");	
}

int contabomba (char *jogo,char *bombas,int *L,int *C,int linha,int coluna){
	
	unsigned int qtd = 0;
	int i,j;
	
	for (i = linha - 2;i <= linha && i != *L;i++){
		if (i < 0) i++;
		for (j = coluna - 2;j <= coluna && j != *C;j++){
			if (j < 0) j++;
			if (*(bombas + i*MAX + j) == 1)
				qtd++;
		}
	}
	
	return qtd;
} 

void revela (char *jogo,char *bombas,int *L,int *C,int linha,int coluna,int *encerra){
	
	int i,j,qtd,end = 0;
	
	for (i = linha - 2;i <= linha && i != *L;i++){
		if (i < 0) i++;
		for (j = coluna - 2;j <= coluna && j != *C;j++){
		   	if (j < 0) j++;
			if (*(jogo + i*MAX + j) == '*' || *(jogo + i*MAX + j) == 'F'){
				end++;
				qtd = contabomba (jogo,bombas,L,C,i+1,j+1);
				if (qtd > 0)
					*(jogo + i*MAX + j) = (char) qtd + '0'; /*Mostra a quantidade de bombas ao redor*/
				else
					*(jogo + i*MAX + j) = ' ';
			}
		}
	}
	
	*encerra += end;
}

int contaast (char *jogo,int *L,int *C,int linha,int coluna){
	
	unsigned int qtd = 0;
	int i,j;
	
	for (i = linha - 2;i <= linha && i != *L;i++){
		if (i < 0) i++;
		for (j = coluna - 2;j <= coluna && j != *C;j++){
			if (j < 0) j++;
			if (*(jogo + i*MAX + j) == '*')
				qtd++;
		}
	}
	
	return qtd;
}

void expande (char *jogo,char *bombas,int *L,int *C,int *encerra){
	
	int i,j,fez = 0;
	
	for (i = 0;i < *L;i++)
		for (j = 0;j < *C;j++)
			if (*(jogo + i*MAX + j) == ' ' && contaast(jogo,L,C,i+1,j+1) > 0){
				revela(jogo,bombas,L,C,i+1,j+1,encerra);
				fez = 1;
			}
		
	if (fez == 1)
		expande(jogo,bombas,L,C,encerra);			
}

void coordenadas (char *ch, int *linha,int *coluna){
	
	if (*ch != 'F'){
		*linha = (int) *ch - 'a' + 1;
		*coluna = (int) *(ch+1) - 'a' + 1;
	}
	else {
        *linha = (int) *(ch+1) - 'a' + 1;
        *coluna = (int) *(ch+2) - 'a' + 1;	
	}
	
}

int revelado (char *jogo,int *L,int *C){
	
	int qtd = 0,i,j;
	
	for (i=0;i < *L;i++)
		for (j=0;j < *C;j++)
			if (*(jogo + i*MAX + j) != '*' && *(jogo + i*MAX + j) != 'F')
				qtd++;
			
	return qtd;		
}

int existe (char *jogo,int *L,int *C,int linha,int coluna){

	int i,j;
	
	for (i = linha - 2;i <= linha && i != *L;i++){
		if (i < 0) i++;
		for (j = coluna - 2;j <= coluna && j != *C;j++){
		   	if (j < 0) j++;
			if (*(jogo + i*MAX + j) != '*' && *(jogo + i*MAX + j) != 'F')
				return 1;
		}
	}
	
	return 0;	
}

void abre (char *jogo,char *bombas,int *L,int *C,int *encerra){
	
	int i,j,qtd,end=0;
	
	i = rand()%(*L-1);
	j = rand()%(*C-1);
	
	if ((*(jogo + i*MAX + j) == '*' || *(jogo + i*MAX + j) == 'F') && *(bombas + i*MAX + j) != 1 && existe(jogo,L,C,i+1,j+1)){
		qtd = contabomba(jogo,bombas,L,C,i+1,j+1);
		if (qtd > 0){
		   	*(jogo + i*MAX + j) = (char) qtd + '0'; /*Mostra a quantidade de bombas ao redor*/
			end++;
		}
		else{ 
			revela(jogo,bombas,L,C,i+1,j+1,encerra);
			expande(jogo,bombas,L,C,encerra);
		}
	}
	else 
		abre(jogo,bombas,L,C,encerra);
	
	*encerra += end;
}

void leitura (char *string){
	/*Armazena o conteúdo do buffer em string*/
	fgets(string,MAX,stdin);
	/*Verifica se existe \n (limpa o buffer)*/
	char *p = string;
	while (*p && *p != '\n') ++p;
	if (*p) *p = 0; /*Descarta o '\n' no final da string*/
	else{ /*excedeu o tamanho máximo (MAX) da string*/
		scanf("%*[^\n]"); /*Descarta todos os caracteres até encontrar um '\n'*/
		scanf("%*c"); /*Descarta o '\n'*/
	}
}

void joga (char *jogo,char *bombas,int *L,int *C,int *termina,int *dificuldade){

	int i,j, continua = 1, encerra = 0,qtd,jogada = 0,minas,chutes = 0,fez = 0,chutou;
	int linha, coluna;
	char posicao[MAX];
	float porcentagem;
	
	while (continua){
		system("cls");
		mostra(jogo,L,C,termina);
		chutou = 0;
		if (*dificuldade == 3){
			porcentagem = (float) revelado(jogo,L,C)/(*termina);
			if (porcentagem >= 0.2 && fez == 0){
				chutes++; fez++;
			}
			else if (porcentagem >= 0.8 && fez == 1){
				chutes++; fez++;
			}
		}
		
		if (jogada != 0){
			minas = contaminas(jogo,L,C,termina);
			if (*dificuldade == 3)
				printf("Minas restantes: %d                      Chutes disponiveis: %d\n", minas,chutes);
			else 
				printf("Minas restantes: %d\n", minas);
		}
		putchar('\n');
		
		printf("Insira 'I' (sem aspas) para ver as instrucoes.\n\n");	
		printf("Selecione uma posicao: "); leitura(posicao); coordenadas(posicao,&linha,&coluna);
		
		while ((linha < 1 || linha > *L || coluna < 1 || coluna > *C) && posicao[0] != 'I' && posicao[0] != 'C'){
			puts("POSICAO INEXISTENTE!!! Tente novamente... ");
			printf("Selecione uma posicao: "); leitura(posicao); coordenadas(posicao,&linha,&coluna);
		}
		
		if (posicao[0] == 'I'){
			system("cls");
			instrucoes();
			printf("\nPressione <ENTER> para continuar...");
			while (getchar()!='\n');
			continue;
		}
		
		while (posicao[0] == 'C' && *dificuldade == 3)   /*Chute*/
			if (chutes == 0){
				printf("Voce nao possui chutes...\n");
				system("PAUSE"); 
				chutou = -1; break;
			}
			else {
				srand(time(NULL));
			 	abre(jogo,bombas,L,C,&encerra);
	 	 	    chutes--; chutou = 1;
	 	 	    jogada++; break;
			 }
			 
		if (chutou != 0)
			continue;	 
		
		if (jogada == 0)
			geramina(bombas,L,C,termina,dificuldade,linha-1,coluna-1);
		
		if (*(jogo + (linha-1)*MAX + (coluna-1)) != '*' && *(jogo + (linha-1)*MAX + (coluna-1)) != 'F'){
			puts("POSICAO JA ESCOLHIDA!!! Tente novamente... ");
			system("PAUSE"); continue;
		}
		
		jogada++;
		
		if (posicao[0] != 'F'){
			if (*(bombas + (linha-1)*MAX + (coluna-1)) == 1){			/*Caiu na bomba :(*/
				continua = 0;
				for (i = 0;i < *L;i++)
					for (j = 0;j < *C;j++)
						if (*(bombas + i*MAX + j) == 1)
							*(jogo + i*MAX + j) = 1;
				system("cls");		
				mostra(jogo,L,C,termina);
				printf("Minas restantes: %d\n", minas);
				puts("\nVOCE PERDEU!!! Tente novamente.");		
			}
			else{
				qtd = contabomba(jogo,bombas,L,C,linha,coluna);
				if (qtd > 0){
					*(jogo + (linha-1)*MAX + (coluna-1)) = (char) qtd + '0'; /*Mostra a quantidade de bombas ao redor*/
					encerra++;
				}
				else{ 
					revela(jogo,bombas,L,C,linha,coluna,&encerra);
					expande(jogo,bombas,L,C,&encerra);
				}
			}
			
			if (encerra == *termina){
				
				for (i = 0;i < *L;i++)
					for (j = 0;j < *C;j++)
						if (*(bombas + i*MAX +j) == 1)
							*(jogo + i*MAX + j) = 2; 
				
				continua = 0;
				system("cls");
				mostra(jogo,L,C,termina);
				printf("Minas restantes: %d\n", minas);
				putchar('\n');
				puts("PARABENS!!!! VOCE VENCEU!!");
			}
		}
		else if (*(jogo + (linha-1)*MAX + coluna-1) == 'F')
					*(jogo + (linha-1)*MAX + coluna-1) = '*';
			 else *(jogo + (linha-1)*MAX + coluna-1) = 'F';
	}
	
}