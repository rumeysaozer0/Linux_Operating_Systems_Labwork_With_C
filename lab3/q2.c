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
   char *FileName2=args[2];
   char str1[16];
   char str2[16];
   strcpy(str1, args[1]);
   strcpy(str2, ".gz");
   strcat(str1, str2);
   //printf("%s",str1);
   //char *gz="abc.txt.gz";
   FILE *fp = fopen(FileName, "w+");
   FILE *fr = fopen(FileName, "r");
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
    printf("[CHILD1]");
    printf("Creating %s with random letters... \n",FileName );

      //Creating file and fill it with random integers.
       for(i=0; i<40000; i++){
       char c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
       fprintf(fp,"%c",c);
       }
       fclose(fp);
       sleep(1);

}
  if(children==1){
    printf("[CHILD2]");
    printf("Executing Zip Command\n");
    execlp("gzip","gzip","-k",args[1],NULL);


}

 if(children==2){
   printf("[CHILD3]");
   printf("Executing ls Command\n");
   execl("/bin/ls", "ls", "-l" , "-t", (char *) 0);
   sleep(1);

}
}

return 0;}

/*
rumeysa@rumeysa-VirtualBox:~/Desktop/lab3$ gcc q2.c -o q2
rumeysa@rumeysa-VirtualBox:~/Desktop/lab3$ ./q2 chars 40000
[CHILD1]Creating chars with random letters... 
[CHILD2]Executing Zip Command
[CHILD3]Executing ls Command
total 112
-rw-r--r-- 1 rumeysa rumeysa 40000 May 18 06:50 chars
-rw-r--r-- 1 rumeysa rumeysa 25337 May 18 06:50 chars.gz
-rwxr-xr-x 1 rumeysa rumeysa 13120 May 18 06:50 q2
-rw-rw-r-- 1 rumeysa rumeysa  2075 May 18 06:50 q1.c
-rw-r--r-- 1 rumeysa rumeysa    60 May 18 06:49 nums.txt
-rwxr-xr-x 1 rumeysa rumeysa 13040 May 18 06:48 q1
-rw-rw-r-- 1 rumeysa rumeysa  1593 May 14 16:20 q2.c
[PARENT] 8551 spawned 3/3 children
rumeysa@rumeysa-VirtualBox:~/Desktop/lab3$ 
*/
