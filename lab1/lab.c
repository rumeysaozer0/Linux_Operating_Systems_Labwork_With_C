#include <stdio.h>
#include <stdlib.h>
int main(){

  int i,j;
  int array[10][10];
	for(i = 0; i < 10; ++i){
		
		for(j = 0; j < 10; ++j){
		array[i][j] = rand()%10000+1;
		printf("%d ", array[i][j]);
		}
		printf("\n");
	}

	return 0;
}

// gcc lab.c
// ./lab | sort -k 3 -o sorted.txt
// cat sorted.txt
