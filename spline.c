//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//-INCLUDE--------------------------------------------------------------------//
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//-DEFINE---------------------------------------------------------------------//
#define FIXED_POINT_FRACTIONAL_BITS 10
#define NUM 1
#define START -3
#define WIDTH 6

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//-TYPEDEF--------------------------------------------------------------------//
typedef double	matrix[3][3];
typedef	double	vector[3];

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//-DECLARATIONS---------------------------------------------------------------//
double determinant_3(matrix m);
double determinant_2(matrix m);

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//-FUNCTIONS------------------------------------------------------------------//
void createSplines(uint32_t num, uint32_t start, uint32_t width, vector splines){

	//printf("In createSplines\n");
	for(int i = 0; i < num; i++){
		
		vector x;
		vector y;
		vector coeffs = {0,0,0};
		x[0] = (start + i * width);
		x[1] = (start + i * width + width / 2);
		x[2] = (start + i * width + width -1);

		y[0] = exp(x[0]);
		y[1] = exp(x[1]);
		y[2] = exp(x[2]);

//printVector(x);
//printVector(y);
//printVector(coeffs);
		polySolve(x, y, coeffs);
		splines[i] = *coeffs;
	}
}

void polySolve(vector x, vector y, vector coeffs){
	//printf("In polySolve\n");
	matrix poly;	//Create matrix of polynomials

	poly[0][0] = x[0] * x[0];	poly[0][1] = x[0];	poly[0][2] = 1;
	poly[1][0] = x[1] * x[1];	poly[1][1] = x[1];	poly[1][2] = 1;
	poly[2][0] = x[2] * x[2];	poly[2][1] = x[2];	poly[2][2] = 1;

	matrixInverse(poly, x, y, coeffs);
	return;
}

void matrixInverse(matrix poly, vector x, vector y, vector coeffs){
	//printf("In matrixInverse\n");
	double det;
	det = determinant_3(poly);	//good operation
 	cofactor_3(poly);		//good operation
	transpose(poly);		//good operation
	matrixDivide(poly,det);		//good operation
	matrixMult(poly, x, y, coeffs); 

	return;
}


void cofactor_3(matrix m){
	//printf("In cofactor_3\n");

	matrix cof00 = {{m[1][1],m[1][2]},{m[2][1], m[2][2]}};
	matrix cof01 = {{m[1][0],m[1][2]},{m[2][0], m[2][2]}};
	matrix cof02 = {{m[1][0],m[1][1]},{m[2][0], m[2][1]}};
	matrix cof10 = {{m[0][1],m[0][2]},{m[2][1], m[2][2]}};
	matrix cof11 = {{m[0][0],m[0][2]},{m[2][0], m[2][2]}};
	matrix cof12 = {{m[0][0],m[0][1]},{m[2][0], m[2][1]}};
	matrix cof20 = {{m[0][1],m[0][2]},{m[1][1], m[1][2]}};
	matrix cof21 = {{m[0][0],m[0][2]},{m[1][0], m[1][2]}};
	matrix cof22 = {{m[0][0],m[0][1]},{m[1][0], m[1][1]}};

	m[0][0] =  determinant_2(cof00);
	m[0][1] = -determinant_2(cof01);
	m[0][2] =  determinant_2(cof02);
	m[1][0] = -determinant_2(cof10);
	m[1][1] =  determinant_2(cof11);
	m[1][2] = -determinant_2(cof12);
	m[2][0] =  determinant_2(cof20);
	m[2][1] = -determinant_2(cof21);
	m[2][2] =  determinant_2(cof22);

	return;
}

void transpose(matrix m){
	//printf("In transpose\n");
	matrix transpose;
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j  < 3; j++){
			transpose[i][j] = m[i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j  < 3; j++){
			m[j][i] = transpose[i][j];
		}
	}
	return;
}

void matrixDivide(matrix m, double divisor){
	//printf("In matrixDivide\n");
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j  < 3; j++){
			m[i][j] = m[i][j] / divisor;
		}
	}
	return;
}

void matrixMult(matrix m, vector x, vector y, vector coeffs){
	//printf("In matrixMult\n");

	printMatrix(m);
	printf("\n");
	printVector(x);
	printf("\n");
	printVector(y);
	printf("\n");
	printVector(coeffs);
	printf("\n");

	int i;
	for(i = 0; i < 3; i++){
		coeffs[i] = m[i][0]*y[0] + m[i][1]*y[1] + m[i][2]*y[2];
	}

	printMatrix(m);
	printf("\n");
	printVector(x);
	printf("\n");
	printVector(y);
	printf("\n");
	printVector(coeffs);
	printf("\n");
	printf("\n");

	return;
}

double determinant_2(matrix m){
	//printf("In determinant_2\n");
	double determinant;
	determinant = m[0][0] * m[1][1] - m[0][1] * m[1][0];
	return determinant;
}

double determinant_3(matrix m){
	//printf("In determinant_3\n");
	int i;
	double determinant;	
	for(i=0;i<3;i++)
		determinant = determinant + (m[0][i]*(m[1][(i+1)%3]*m[2][(i+2)%3] - m[1][(i+2)%3]*m[2][(i+1)%3]));
	return determinant;

}

void printVector(vector v){
	//printf("In printVector\n");
	int i;
	for(i = 0; i < 3; i++){
		printf("%f\t",v[i]);
	}
	printf("\n\n");
}

void printMatrix(matrix m){
	//printf("In printMatrix\n");
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%f\t",m[i][j]);
		}
	printf("\n\n");
	}
}

int main(/*int argc, char* argv[]*/){
	//printf("In main\n");
	vector splines[NUM];
	createSplines(NUM, START, WIDTH, splines);
	printVector(splines[0]);
}


