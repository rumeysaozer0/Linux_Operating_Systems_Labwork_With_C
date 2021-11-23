#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
int main(){
	FILE * dosya;
	pid_t child1;
	child1 = fork();
	  wait(NULL);
	int ch;
	static int count=0;
	static int a=100000;

	if(child1 == 0){
	printf("[PARENT Child process ID: %d\n", getpid());
	//open data.txt file only read mode.
	dosya = fopen("data.txt", "r"); 
	while(1){
	ch = fgetc(dosya);
	if (ch == EOF)
	 break;
	if (isdigit(ch))
	 ++count;
}
	printf("[CHILD1] Number of letters %d\n", 100000-count);
	fclose(dosya);
 	}else if(child1 > 0){
	pid_t child2 = fork();
	wait(NULL);
	if(child2 == 0){
	printf("[PARENT] Child process ID: %d \n", getpid());
	dosya = fopen("data.txt","r");
	  while(1){
	ch= fgetc(dosya);
	if (ch == EOF)
	break;
	
	if(isdigit(ch))
	++count;
	
	printf("[CHILD2]Number of digits %d\n", count);
	fclose(dosya);

      }
	}
 	else{
	printf("error");
	exit(1);
	}
      }else{
	printf("error");
	exit(1);
	}
	return 0;
}

/*
rumeysa@rumeysa-VirtualBox:~/Desktop/lab2$ gcc q2.c -o q2
rumeysa@rumeysa-VirtualBox:~/Desktop/lab2$ ./q2
[PARENT Child process ID: 7545
[CHILD1] Number of letters 72147
[PARENT] Child process ID: 7546 
[CHILD2]Number of digits 1
errorrumeysa@rumeysa-VirtualBox:~/Desktop/lab2$ 

*/

