#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#define MAX_PIDS 32
#define COUNT 3

volatile pid_t *pids;
int main(int argc, char *args[]) {
   srand((unsigned)time(NULL));

    int count = COUNT, children = 0;
    char *FileName=args[1];
    int range1=atoi(args[3]);
    char *FileName2=args[2];
    int range2=atoi(args[4]);
    FILE *fp = fopen(FileName, "w+");
    FILE *fp2 = fopen(FileName2, "w+");
    int i,z,j,index,temp;
    char line_number;
    char line_buffer[256];
    pid_t retpid = 1;

    while (count-- > 0 && retpid > 0)

        if ((retpid = fork()) > 0)
            children++;wait(NULL);



    if (retpid != 0) {
        printf("Parent %d spawned %d/%d children\n",
            getpid(), children, COUNT);
		while (children-- > 0)
         wait(NULL);
}
 else {
  if(children==2){
printf("Child 1 Start:\n");
printf("Creating %s with %d integers... \n",FileName,range1 );

	//Creating file and fill it with random integers.
	 for(i=0; i<range1; i++){
	 int c = (rand() % 900)+100;
	 fprintf(fp,"%d\n",c);
	 }
	 fclose(fp);

printf("Child 1 Stop.\n");

}
  if(children==1){

printf("Child 2 Start:\n");
printf("Creating %s with %d integers... \n",FileName2,range2 );

	//Creating file and fill it with random integers.
sleep(2);
	 for(i=0; i<range2; i++){
	 int d = ((rand() % 400)+100)+((rand() % 400)+99);
	 fprintf(fp2,"%d\n",d);
	 }
	 fclose(fp2);

printf("Child 2 stop:\n");

}

 if(children==0){
sleep(3);
printf("Child 3 Start.\n");
execl("/usr/bin/sort","-n", args[2], args[1], (char*)NULL);

printf("Child 3 Stop.\n");

}

    return 0;
}}

/*
rumeysa@rumeysa-VirtualBox:~/Desktop/lab3$ gcc q3.c -o q3
rumeysa@rumeysa-VirtualBox:~/Desktop/lab3$ ./q3 randfile1.txt randfile2.txt 40 70
Child 1 Start:
Creating randfile1.txt with 40 integers... 
Child 1 Stop.
Parent 8577 spawned 3/3 children
Child 2 Start:
Creating randfile2.txt with 70 integers... 
Child 2 stop:
Child 3 Start.
125
135
157
188
223
.
.
.
*/
