#include <stdio.h>

int main(){

	int somenumbers[5];
	int *ptr = somenumbers; // == &somenumbers[0]

	int v =2;

	for(; ptr<&somenumbers[5]; ptr++){
		*ptr = v;
		v = v * 2;
	}

	int i;
	for(i = 0; i < 5; i++){
		printf("%d\n", somenumbers[i]);
	}
	return 0;
}
