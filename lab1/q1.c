#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

	int M = atoi(argv[1]);
	int N = atoi(argv[2]);
	int i, j;
	int array[M][N];
	FILE * dosya;

	dosya = fopen("numbers.txt", "w+");

	for(i = 0; i < M; ++i){
		for(j = 0; j < N; ++j){
			array[i][j] = rand() % 100 + 1;
			fprintf(dosya,"%d ", array[i][j]);
		}
		fprintf(dosya, "\n");
	}
	fclose(dosya);
	return 0;
}


/*
rumeysa@rumeysa-VirtualBox:~/Desktop/lab1$ gcc q1.c -o q1
rumeysa@rumeysa-VirtualBox:~/Desktop/lab1$ ./q1 5 3
rumeysa@rumeysa-VirtualBox:~/Desktop/lab1$ cat numbers.txt
84 87 78 
16 94 36 
87 93 50 
22 63 28 
91 60 64 
rumeysa@rumeysa-VirtualBox:~/Desktop/lab1$ 




/
