#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int main(){
	
	char mat[MAX][MAX],pal[MAX],auxpal[MAX],inv[MAX];
	int i,j,dim,x,cont=0,vdd=0,tpal,tinv,k,w;
	puts("MATRIZ CACA PALAVRAS:");
	puts("DIGITE A DIMENSAO:");
	scanf("%d",&dim);
	//caso a dimensão não seja suportada
	while(dim<=0||dim>MAX){
		puts("Invalido, tente novamente:");
		scanf("%d",&dim);
	}
	//lendo a matriz
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("[%d][%d]",i+1,j+1);
			scanf(" %c",&mat[i][j]);
			system("cls");
		}
	}
	//mostra matriz na tela
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("%c",mat[i][j]);
		}
		puts(" ");
	}
	//case sensitive matriz
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(mat[i][j]>='a'&&mat[i][j]<='z'){
				mat[i][j]-=32;
			}
		}
	}
	//lendo a palavra a ser procurada
	puts("Digite a palavra a ser procurada:");
	fflush(stdin);
	gets(pal);
	fflush(stdin);
	i=0;
	//caso a palavra tenha tamanho=1 ou 0 não pode ser considerada palavra
	while(strlen(pal)==1||strlen(pal)==0){
		printf("Digite uma palavra por favor !\n");
		printf("Tente novamente!\n");
		gets(pal);
		i++;
	}
	
	tpal=strlen(pal);//tamanho da minha palavra a ser procurada
	for(i=0;i<tpal;i++){
		auxpal[i]=pal[i];
	}
	auxpal[i]='\0';
	
	//ignora espaços da palavra
	for (i=0;pal[i]!='\0';i++) {
		if (pal[i]==' '){
			for(j=i;j<tpal;j++){
				pal[j]=pal[j+1];
			}
		}
	}
	//case sensitive palavra
	for(i=0;pal[i]!='\0';i++){
		if(pal[i]>='a'&&pal[i]<='z'){
			pal[i]-=32;
		}
	}
	//inversão de palavra
	k=0;
	for(i=tpal-1;i>=0;i--){
		inv[k]=pal[i];
		k++;
	}
	inv[k]='\0';
	tinv=strlen(inv);//tamanho da palavra invertida
	//case sensitive palavra invertida
	for(i=0;inv[i]!='\0';i++){
		if(inv[i]>='a'&&inv[i]<='z'){
			inv[i]-=32;
		}
	}
	//verificar se a palavra é palindromo
	for(i=0,j=tpal-1;pal[i]!='\0';i++,j--){
		if(pal[i]==pal[j]){
			vdd=1;
		}
		else{
			vdd=0;
			break;
		}
	}
	//verificação das linhas da matriz com a substring
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(mat[i][j]==pal[0]){
				x=0;
				for(k=0;k<tpal;k++){
					if(mat[i][j+k]==pal[k]){
						x++;
					}
					if(x==tpal){
						cont++;
					}
				}
			}
			//se não for palindromo ele inverte e conta ao contrario caso apareça
			if(vdd==0){
				if(mat[i][j]==inv[0]){
					x=0;
					for(k=0;k<tinv;k++){
						if(mat[i][j+k]==inv[k]){
							x++;
						}
						if(x==tinv){
							cont++;
						}
					}
                }		
			}
		}
	}
	//verificação das colunas com a substring
	for(j=0;j<dim;j++){
		for(i=0;i<dim;i++){
			if(mat[i][j]==pal[0]){
				x=0;
				for(k=0;k<tpal;k++){
					if(mat[i+k][j]==pal[k]){
						x++;
					}
					if(x==tpal){
						cont++;
					}
				}
			}
			//se não for palindromo ele inverte e conta ao contrario caso apareça
			if(vdd==0){
				if(mat[i][j]==inv[0]){
					x=0;
					for(k=0;k<tinv;k++){
						if(mat[i+k][j]==inv[k]){
							x++;
						}
						if(x==tinv){
							cont++;
						}
					}
                }		
			}
		}
	}
	//diagonal principal e sentido da diagonal principal pra cima
	for(i=0;i<dim;i++){
		for(k=0;k<dim;k++){
			if(mat[i+k][k]==pal[0]){
				x=0;
				for(w=0;w<tpal;w++){
					if(mat[i+k+w][w+k]==pal[w]){
						x++;
					}
					if(x==tpal){
						cont++;
					}
				}
			}			
		}
		if(vdd==0){
			for(k=0;k<dim;k++){
				if(mat[i+k][k]==inv[0]){
					x=0;
					for(w=0;w<tinv;w++){
						if(mat[i+k+w][w+k]==inv[w]){
							x++;
						}
						if(x==tinv){
							cont++;
						}
					}
                }			
            }	
		}
	}
	//diagonal principal pra baixo sem contar a diagonal principal
	for(j=1;j<dim;j++){
		for(k=0;k<dim;k++){
			if(mat[k][j+k]==pal[0]){
				x=0;
				for(w=0;w<tpal;w++){
					if(mat[k+w][j+k+w]==pal[w]){
						x++;
					}
					if(x==tpal){
						cont++;
					}
				}
			}			
		}
		if(vdd==0){
			for(k=0;k<dim;k++){
				if(mat[k][j+k]==inv[0]){
					x=0;
					for(w=0;w<tinv;w++){
						if(mat[k+w][j+k+w]==inv[w]){
							x++;
						}
						if(x==tinv){
							cont++;
						}
					}
                }			
            }	
		}
	}
	//diagonal secundaria e no sentido pra baixo
	for(i=0;i<dim;i++){
		j=dim-1;
		for(k=0;k<dim;k++){
			if(mat[i+k][j-k]==pal[0]){
				x=0;
				for(w=0;w<tpal;w++){
					if(mat[i+k+w][j-w-k]==pal[w]){
						x++;
					}
					if(x==tpal){
						cont++;
					}
				}
			}			
		}
		if(vdd==0){
			for(k=0;k<dim;k++){
				if(mat[i+k][j-k]==inv[0]){
					x=0;
					for(w=0;w<tinv;w++){
						if(mat[i+k+w][j-w-k]==inv[w]){
							x++;
						}
						if(x==tinv){
							cont++;
						}
					}
                }			
            }	
		}
	}
	//acima da diagonal secundaria sem incluir ela
	for(j=dim-2;j>=0;j--){
		i=0;
		for(k=0;k<dim;k++){
			if(mat[i+k][j-k]==pal[0]){
				x=0;
				for(w=0;w<tpal;w++){
					if(mat[i+k+w][j-k-w]==pal[w]){
						x++;
					}
					if(x==tpal){
						cont++;
					}
				}
			}			
		}
		if(vdd==0){
			for(k=0;k<dim;k++){
				if(mat[i+k][j-k]==inv[0]){
					x=0;
					for(w=0;w<tinv;w++){
						if(mat[i+k+w][j-k-w]==inv[w]){
							x++;
						}
						if(x==tinv){
							cont++;
						}
					}
                }			
            }	
		}
	}
	
	printf("A palavra %s aparece %d vez(es)",auxpal,cont);
	return 0;
}

