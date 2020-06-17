#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

#define NUM 1
#define START -1
#define WIDTH 2

typedef double vector_n[4];
typedef double matrix_n[4][4];
int dim = 4;

double deter(matrix_n m, int k){
	double determinant=0.0, z=1.0;
	matrix_n mt;
	int a, b, c, x, y;
	if(k==1){
		return(m[0][0]);
	}
	else{
		determinant=0;
		for(a=0;a<k;++a){
			x=0;
			y=0;
			for(b=0;b<k;++b){
				for(c=0;c<k;++c){
					mt[b][c]=0;
					if((b != 0) && (c != a)){
						mt[x][y]=m[b][c];
						if(y<(k-2))
							y++;
						else{
							y=0;
							x++;
						}
					}
				}
			}
			determinant = determinant + z * (m[0][a] * deter(mt,k-1));
			z = -1 * z;
		}
	}
	return(determinant);
}

void invert(matrix_n comatr, int f){
	matrix_n matr, cofact;
	int a, b, c, d, x, y;
	for(c=0; c<f; ++c){
		for(d=0; d<f; ++d){
			x=0;
			y=0;
			for(a=0;a<f; ++a){
				for(b=0; b<f; ++b){
					if(a != c && b != d){
						matr[x][y]=comatr[a][b];
						if(y<(f-2))
							y++;
						else{
							y=0;
							x++;
						}
					}
				}
			}
		cofact[c][d] = pow(-1,c + d) * deter(matr,f-1);
		}
	}
	transpose_divide(comatr, cofact, f);
}

void transpose_divide(matrix_n matr, matrix_n m1, int r){
	matrix_n inv_matrix, tran;
	double d;
	int a,b;
	for(a=0;a<r;++a){
		for(b=0;b<r;++b){
			tran[a][b]=m1[b][a];
		}
	}
	d=deter(matr, r);
	for(a=0;a<r;++a){
		for(b=0;b<r;++b){
			inv_matrix[a][b]=tran[a][b] / d;
		}
	}
	for(a=0;a<r;++a){
		for(b=0;b<r;++b){
			matr[a][b]=inv_matrix[a][b];
		}
	}	
}

void printVector(vector_n x, int dim){
	printf("In printVector\n");
	int i;
	for(i = 0; i < dim; i++){
		printf("%f\t",x[i]);
	}
	printf("\n\n");
}

void printMatrix(matrix_n m, int dim){
	//printf("In printMatrix\n");
	int i,j;
	for(i = 0; i < dim; i++){
		for(j = 0; j < dim; j++){
			printf("%f\t",m[i][j]);
		}
	printf("\n\n");
	}
}

void vector_init(vector_n x, vector_n y){
	for(int i = 0; i < dim; i++){
		x[i] = START + i * (float) WIDTH/dim; 
		y[i] = exp(START + i * (float) WIDTH/dim);
	}
}

void matrix_init(matrix_n m, vector_n x, int dim){
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			m[i][j] = pow(x[i], dim-1-j);
		}
	}
}

void matrixMult(matrix_n m, vector_n x, vector_n coeffs, int dim){
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			coeffs[i] += m[i][j] * x[j];
		}
	}

}

double evalPoly(){

}

double evalExp(){

}

int main(/*int argc, char* argv[]*/){


	vector_n x[NUM];
	vector_n y[NUM];
	vector_init(x,y);
	printVector(x, dim);
	printVector(y, dim);

	matrix_n m;
	matrix_init(m, x, dim);
	printMatrix(m, dim);
	invert(m, dim);

	vector_n coeffs[NUM];
	matrixMult(m, y, coeffs, dim);
	printVector(coeffs,dim);

	double evaluation, actual;
	evaluation = evalPoly();
	actual = evalExp();
		

	return 0;
}



