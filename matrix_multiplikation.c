#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int** matrix;
    int m;
    int n;
}Matrix;

Matrix* matrix_erschaffen(int* zah, int m, int n){
    int** a = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++){
	a[i] = (int*)malloc(sizeof(int)*n);
	for (int j = 0; j < n; j++){
	    a[i][j] = zah[i*n+j];
	}
    }
    Matrix* mat_a = (Matrix*)malloc(sizeof(Matrix));
    mat_a->matrix = a;
    mat_a->m = m;
    mat_a->n = n;
    return mat_a;
}

void matrix_befreien(Matrix* matrix){
     for (int i = 0; i < matrix->m; i++){
	free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

Matrix* matrix_multiplizieren(Matrix* a, Matrix* b){
   if (a->n != b->m) return NULL; 
   Matrix* c = (Matrix*)malloc(sizeof(Matrix));
   c->m = a->m;
   c->n = b->n;
   c->matrix = (int**)malloc((c->m)*sizeof(int*));
  for (int i = 0; i < c->m; i++){
       c->matrix[i] = calloc(c->n, sizeof(int));
   }
  for (int i = 0; i < c->m; i++){ 
       for (int k = 0; k < c->n; k++){
	   for (int j = 0; j < a->n; j++){
	       (c->matrix)[i][k] += (a->matrix)[i][j] * (b->matrix)[j][k];
	   }
       }
   }
   return c;
}

void matrix_drucken(Matrix* matrix){
    printf("\n");
    for (int i = 0; i < matrix->m; i++){
	for (int j = 0; j < matrix->n; j++){
	    printf("%d ", (matrix->matrix)[i][j]);
	}
	printf("\n");
    }
}

int main(){
    int a_zah[6] = {1,2,3,4,5,6};
    int a_m = 2;
    int a_n = 3;
    Matrix* a = matrix_erschaffen(a_zah, a_m, a_n);  
    int b_zah[9] = {1,2,3,4,5,6,7,8,9};
    int b_m = 3;
    int b_n = 3;
    Matrix* b = matrix_erschaffen(b_zah, b_m, b_n);
    Matrix* c = matrix_multiplizieren(a, b);
    matrix_drucken(a);
    matrix_drucken(b);
    matrix_drucken(c);
    matrix_befreien(a);
    a = NULL;
    matrix_befreien(b);
    b = NULL;
    matrix_befreien(c);
    c = NULL;
    return 0;
}


