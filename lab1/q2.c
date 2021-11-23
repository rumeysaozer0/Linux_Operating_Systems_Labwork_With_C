#include <stdio.h>
#include <stdlib.h>
int main(){

	int i;
	FILE * dosya;
	dosya = fopen("numbers2.txt", "w+");

	for(i = 0; i < 1000; ++i){

	fprintf(dosya,"%d ", rand()%900+100);
	fprintf(dosya, "\n");
 	}
	fclose(dosya);

	return 0;
}

/*
cat numbers2.txt | grep "^2"
*/
