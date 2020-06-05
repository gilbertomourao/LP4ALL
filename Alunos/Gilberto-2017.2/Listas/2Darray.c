#include <stdio.h>
#include <stdlib.h>

typedef struct MatrixNode_{
	char ch;
	struct MatrixNode_ *next_row;
	struct MatrixNode_ *next_col;
	struct MatrixNode_ *next_diagP;
	struct MatrixNode_ *next_diagS;
}MatrixNode;

void limpaBuffer();
void createMatrix(MatrixNode**,int,int);
void readMatrix (MatrixNode**,int,int);
MatrixNode* createNode();
void displayMatrix(MatrixNode *);
void destroyMatrix(MatrixNode **);

int main(){
	
	MatrixNode *head = NULL;
	
	createMatrix(&head,3,3);
	displayMatrix(head);
	readMatrix(&head,3,3);
	
	
	destroyMatrix(&head);
	
	return 0;
}

void limpaBuffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
} 

void createMatrix (MatrixNode** head,int rows,int cols){
	
	MatrixNode *mat[rows][cols];
	int r,c;
	/*Atribui os elementos*/
	for(r = 0; r < rows; ++r){
        for(c = 0; c < cols; ++c){
            mat[r][c] = createNode();
        }
    }
    /*Faz o link*/
    for(r = 0; r < rows; ++r){
        for(c = 0; c < cols; ++c){
            if(c < cols-1)
                mat[r][c]->next_col = mat[r][c+1];
            if(r < rows-1)
                mat[r][c]->next_row = mat[r+1][c];
            if (r < rows-1 && c < cols-1)
            	mat[r][c]->next_diagP = mat[r+1][c+1];
            if (r < rows-1 && c > 0)
            	mat[r][c]->next_diagS = mat[r+1][c-1];
        }
    }
    *head = mat[0][0];	
}

void readMatrix (MatrixNode** head,int rows,int cols){
	
	MatrixNode *row = *head;
	int r = 1,c;
	
	while (row){
		MatrixNode *col = row;
		c = 1;
		while (col){
			printf("Posicao [%d][%d]: ",r,c); 
			col->ch = getchar();
			if (col->ch == '\n')
				col->ch = ' ';
			else limpaBuffer();
			col = col->next_col;
			c++;
			displayMatrix(*head);
		}
		putchar('\n');
		row = row->next_row;
		r++;
	}
	
}

MatrixNode* createNode(){
	MatrixNode *temp = (MatrixNode*)malloc(sizeof(MatrixNode));
	
	if (temp == NULL)
		exit(1);
	temp->next_col = NULL;
	temp->next_row = NULL;
	temp->next_diagP = NULL;
	temp->next_diagS = NULL;
	temp->ch = '*';
	
	return temp;
}

void displayMatrix(MatrixNode *head){
	
	MatrixNode *row = head;
	
	while (row){
		MatrixNode *col = row;
		while (col){
			printf("%c ",col->ch);
			col = col->next_col;
		}
		putchar('\n');
		row = row->next_row;
	}
}

void destroyMatrix(MatrixNode **head){
	
	if (!head) return;
	
	MatrixNode *row = *head,*temp1,*temp2;
	
	while (row){
		temp2 = row->next_row;
		MatrixNode *col = row;
		while (col){
			temp1 = col->next_col;
			free(col);
			col = temp1;
		}
		row = temp2;
	}
	*head = NULL;
}