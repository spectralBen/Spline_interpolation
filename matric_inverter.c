#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

typedef double matrix_n[5][5];

double deter(matrix_n m, int n){

	int a, b, c, x, y;
	double determinant = 0.0; 
	int z = 1.0;
	matrix_n temp_m;
	if(n == 1){return(m[0][0]);}
	else{
		determinant = 0;
		for(int i = 0; i < n; i++){
			x=0;
			y=0;
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					temp_m[j][k]=0;
					if((j != 0) && (k != i)){
						temp_m[x][y]=m[j][k];
						if(y < (n-2)){y++;}
						else{
							y=0;
							x++;
						}
					}
				}
			}
			determinant = determinant + z * (m[0][i] * deter(temp_m,n-1));
			z = -1 * z;
		}
	}
	return(determinant);
}

void invert(matrix_n co_m, int n){
	matrix_n m;
	matrix_n cof;
	int x, y;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; ++j){
			x=0;
			y=0;
			for(int k=0;k<n; k++){
				for(int l=0; l<n; l++){
					if(k != i && l != j){
						m[x][y]=co_m[k][l];
						if(y<(n-2))
							y++;
						else{
							y=0;
							x++;
						}
					}
				}
			}
		cof[i][j] = pow(-1,i + j) * deter(m,n-1);
		}
	}
	transpose_divide(co_m, cof, n);
}

void transpose_divide(matrix_n m, matrix_n m1, int r){
	matrix_n inv_m;
	matrix_n tran_m;
	double d;
	int a,b;
	for(a=0;a<r;++a){
		for(b=0;b<r;++b){
			tran_m[a][b]=m1[b][a];
		}
	}
	d=deter(m, r);
	for(a=0;a<r;++a){
		for(b=0;b<r;++b){
			inv_m[a][b]=tran_m[a][b] / d;
		}
	}
	for(a=0;a<r;++a){
		for(b=0;b<r;++b){
			m[a][b]=inv_m[a][b];
		}
	}	
}

void printMatrix(matrix_n m, int DIM){
	//printf("In printMatrix\n");
	int i,j;
	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			printf("%f\t",m[i][j]);
		}
	printf("\n\n");
	}
}

int main(/*int argc, char* argv[]*/){

	int dim = 5;

	matrix_n m = {{0,1,1,0,1},{1,0,0,1,0},{0,0,1,1,0},{1,1,1,0,0},{0,1,0,0,0}};
	printMatrix(m,dim);
	invert(m, dim);
	printMatrix(m, dim);
}


