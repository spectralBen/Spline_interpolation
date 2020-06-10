#include <stdio.h>
#include <math.h>	// for functions
#include <time.h>	// for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>	// for sleep()

#define EVALUATION_SIZE 10
/*
double * sin(double x[]){

	static double y[11];
	double time_spent = 0.0;
	clock_t begin = clock();
		
	for(int i = 0; i < EVALUATION_SIZE; i++){
		y[i] = sin(x[i]);
	}

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time Spent: %f", time_spent);	
	return y;
}
*/
double * ln(double x[]){

	static double y[1000000];
	double time_spent = 0.0;
	clock_t begin = clock();
		
	for(int i = 0; i < 1000000; i++){
		y[i] = log(x[i]);
	}


	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time Spent: %0.8f\n", time_spent);	
	return y;
}

double * exponent(double x[]){

	static double y[EVALUATION_SIZE];
	double time_spent = 0.0;
	clock_t begin = clock();
		
	for(int i = 0; i < EVALUATION_SIZE; i++){
		y[i] = exp(x[i]);
	}

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time Spent: %0.8f\n", time_spent);	
	return y;
}

int main(int argc, char* argv[]){
	
	double x[EVALUATION_SIZE];

	for(int i = 0; i<EVALUATION_SIZE; i++){
		x[i] = i;
	}
	double *y_e[EVALUATION_SIZE];
	//double *y_ln;
	//double *y_sin;
	*y_e = exponent(x);
	//y_ln = ln(x);

	for (int i = 0; i < EVALUATION_SIZE; i = i++){
		printf("%0.2f\n", *y_e[i]);
	}
	printf("\n");
	/*for (int i = 0; i < 1000000; i = i + 1000){
		printf("%0.8f ", y_ln[i]);
	}
//	y_sin = sin(x);
	*/return 0;
}

