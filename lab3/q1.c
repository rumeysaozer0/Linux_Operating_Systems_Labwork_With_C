#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include<sys/wait.h>
#define MAX_PIDS 32
#define COUNT 3

volatile pid_t *pids;
int main(int argc, char *args[]) {
   srand((unsigned)time(NULL));

    int count = COUNT, children = 0;
    char *FileName=args[1];
    int range =atoi(args[2]);
    FILE *fp = fopen(FileName, "w+");
    FILE *fr = fopen(FileName, "r");
    int n[range];
    int i,z,j,index,temp;
    char line_number;
    char line_buffer[256];
    pid_t retpid = 1;
    while (count-- > 0 && retpid > 0)

        if ((retpid = fork()) > 0){
            children++;wait(NULL);
}


    if (retpid != 0) {
        printf("[PARENT] %d spawned %d/%d children\n",
            getpid(), children, COUNT);

}
 else {
  if(children==0){
printf("[CHILD1] ");
printf("Creating %s with %d integers... \n",FileName,range );

	//Creating file and fill it with random integers.
	 for(i=0; i<range; i++){
	 int c = (rand() % 900)+100;
	 fprintf(fp,"%d\n",c);
	 }
	 fclose(fp);

}
  if(children==1){
printf("[CHILD2]");
printf("Executing Sort Command\n");
execl("/usr/bin/sort", "-n", args[1], (char*)NULL);

}

 if(children==2){
sleep(1);
printf("[CHILD3]");
z=0;
	 while (fgets(line_buffer, sizeof(line_buffer), fr)) {

        n[z]=atoi(line_buffer);
z++;

    }
for (i = 0; i < (range - 1); ++i)
 {
      for (j = 0; j < range - 1 - i; ++j )
      {
           if (n[j] > n[j+1])
           {
                temp = n[j+1];
                n[j+1] = n[j];
                n[j] = temp;
           }
      }
 }
printf("Min:%d",n[0]);
printf("Max:%d\n",n[range-1]);

}
}

return 0;}

/*
rumeysa@rumeysa-VirtualBox:~/Desktop/lab3$ ./q1 nums.txt 15
[CHILD1] Creating nums.txt with 15 integers... 
[CHILD2]Executing Sort Command
102
230
241
276
294
298
307
331
336
486
544
562
812
892
928
[CHILD3]Min:102Max:928
[PARENT] 8478 spawned 3/3 children
rumeysa@rumeysa-VirtualBox:~/Desktop/lab3$ 
*/
