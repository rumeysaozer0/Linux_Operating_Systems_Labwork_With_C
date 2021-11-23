#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>


int main() {
    pid_t c1Pid, c2Pid;
    FILE *fp = fopen("data1.txt", "w+");
    FILE *fp2 = fopen("data2.txt", "w+");
    FILE *fr = fopen("data1.txt", "r");
    FILE *fr2 = fopen("data2.txt", "r");
    int num;
    char let;
    srand((unsigned)time(NULL));

    c1Pid = fork();

    if(c1Pid == 0) {
        printf("[CHILD1] Wrote:" );
        for (int i = 0; i < 10; i++) {
        int a=(int)(random() % 10);
        fprintf(fp,"%d ",a);
        printf("%d ",a );
      }
printf("to file.\n" );
    } else {
        printf("[PARENT] Child process ID: %d\n", c1Pid);
        wait(NULL);

        c2Pid = fork();

        if(c2Pid == 0) {
          printf("[CHILD2] Wrote:" );
          for (int i = 0; i < 10; i++) {
          char st[] = "abcdefghijklmnopqrstuvwxyz";
          int b=st[(rand() % 26)] ;
          fprintf(fp2,"%c ",b);
          printf("%c ",b);
      }
printf("to file.\n" );
        } else {
            printf("[PARENT] Child process ID: %d\n", c2Pid);
            wait(NULL);
        }
        }
        while ( fscanf(fr, "%c", &let) == 1 ) {
        printf("%c",let );
        }

        while (fscanf(fr2, "%c", &let) == 1 ) {
        printf("%c",let );
    }
	printf("\n");
}

/*
rumeysa@rumeysa-VirtualBox:~/Desktop/lab2$ gcc q6.c -o q6
rumeysa@rumeysa-VirtualBox:~/Desktop/lab2$ ./q6
[PARENT] Child process ID: 8357
[CHILD1] Wrote:4 6 3 1 2 0 1 5 9 3 to file.

[PARENT] Child process ID: 8358
[CHILD2] Wrote:q m f t w k d b f t to file.
4 6 3 1 2 0 1 5 9 3 
q m f t w k d b f t 
rumeysa@rumeysa-VirtualBox:~/Desktop/lab2$ 
*/
