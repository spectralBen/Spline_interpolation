#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

typedef uint32_t matrix[3][3];

void _double_(matrix m){

	int i,j;
	printf("Address of matrix in _double_:\t%d\n", *m);
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			m[i][j] = 2 * m[i][j];
		}
	}

}

int main(/*int argc, char* argv[]*/){

	int i,j;
	matrix m = {{1,2,3},{4,5,6},{7,8,9}};

	printf("Address of matrix in main:\t%d\n", *m);
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%d\t",m[i][j]);
		}
	printf("\n");
	}
	printf("Address of matrix in main after print loop:\t%d\n", *m);
	_double_(&m);

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%d\t",m[i][j]);
		}
	printf("\n");
	}

	return 0;
}
