#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int main(){
	
	char mat[MAX][MAX],pal[MAX],vdp[MAX],vds[MAX],aux;
	int i,j,dim,x,cont=0,vdd,tpal,k,p,w,dp,ds;
	puts("MATRIZ CACA PALAVRAS:");
	puts("DIGITE A DIMENSAO:");
	scanf("%d",&dim);
	//caso a dimensão não seja suportada
	while(dim<=0||dim>=MAX){
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
	//caso a palavra tenha tamanho=1 não pode ser considerada palavra
	while(strlen(pal)==1){
		printf("Nao e palavra!\n");
		printf("Tente novamente!\n");
		gets(pal);
	}
	
	tpal=strlen(pal);//tamanho da minha palavra a ser procurada
	
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
	//verificar se a palavra é palindromo
	for(i=0,j=tpal-1;pal[i]!='\0';i++,j--){
		if(pal[j]!=pal[i]){
			vdd=0;
			break;
		}
		else{
			vdd=1;
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
				for(p=0,w=tpal-1;p<w;p++,w--){
					aux=pal[p];
					pal[p]=pal[w];
					pal[w]=aux;
				}
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
				for(p=0,w=tpal-1;p<w;p++,w--){
					aux=pal[p];
					pal[p]=pal[w];
					pal[w]=aux;
				}
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
			}
		}
	}
	//diagonal principal
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(i==j){
				if(vdd==0){
					for(p=0,w=tpal-1;p<w;p++,w--){
						aux=pal[p];
						pal[p]=pal[w];
						pal[w]=aux;
					}
					if(mat[i][j]==pal[0]){
						x=0;
						for(k=0;k<tpal;k++){
							if(mat[i+k][j+k]==pal[k]){
								x++;
							}
							if(x==tpal){
								cont++;
							}
						}
					}
				}
				if(mat[i][j]==pal[0]){
					x=0;
					for(k=0;k<tpal;k++){
						if(mat[i+k][j+k]==pal[k]){
							x++;
						}
						if(x==tpal){
							cont++;
						}
					}
				}
			}
		}
	}
	//abaixo da diagonal principal
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(j<i){							
				if(vdd==0){
					for(p=0,w=tpal-1;p<w;p++,w--){
						aux=pal[p];
						pal[p]=pal[w];
						pal[w]=aux;
					}
					if(mat[i][j]==pal[0]){
						x=0;
						for(k=0;k<tpal;k++){
							if(mat[i+k][j+k]==pal[k]){
								x++;
							}
							if(x==tpal){
								cont++;
							}
						}
					}
				}
				if(mat[i][j]==pal[0]){
					x=0;
					for(k=0;k<tpal;k++){
						if(mat[i+k][j+k]==pal[k]){
							x++;
						}
						if(x==tpal){
							cont++;
						}
					}
				}
			}
		}
	}
	// acima da diagonal principal
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(i<j){							
				if(vdd==0){
					for(p=0,w=tpal-1;p<w;p++,w--){
						aux=pal[p];
						pal[p]=pal[w];
						pal[w]=aux;
					}
					if(mat[i][j]==pal[0]){
						x=0;
						for(k=0;k<tpal;k++){
							if(mat[i+k][j+k]==pal[k]){
								x++;
							}
							if(x==tpal){
								cont++;
							}
						}
					}
				}
				if(mat[i][j]==pal[0]){
					x=0;
					for(k=0;k<tpal;k++){
						if(mat[i+k][j+k]==pal[k]){
							x++;
						}
						if(x==tpal){
							cont++;
						}
					}
				}
			}
		}
	}
	// diagonal secundaria
	for(j=0;j<dim;j++){
		for(i=0;i<dim;i++){
			if(i+j<dim-1){
				printf("%c",mat[i][j]);
				if(vdd=0){
					for(p=0,w=tpal;i<w;p++,w--){
						aux=pal[p];
						pal[p]=pal[w];
						pal[w]=aux;
					}
					if(mat[i][j]==pal[0]){
						x=0;
						for(k=0;k<tpal;k++){
							if(mat[i+k][j+k]==pal[k]){
								x++;
							}
							if(x==tpal){
								cont++;
							}
						}
					}
				}
				if(mat[i][j]==pal[0]){
					x=0;
					for(k=0;k<tpal;k++){
						if(mat[i+k][j+k]==pal[k]){
							x++;
						}
						if(x==tpal){
							cont++;
						}
					}
				}
			}
		}
	}
	//resultado final
	printf("A palavra %s aparece %d vez(es)",pal,cont);
	return 0;
}