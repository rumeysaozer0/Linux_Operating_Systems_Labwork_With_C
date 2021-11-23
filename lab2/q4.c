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
    FILE *fp = fopen("numbers.txt", "w+");
    FILE *fr = fopen("numbers.txt", "r");
    int numbers[1000000];
    int even=0;
    int num;
    srand((unsigned)time(NULL));

    c1Pid = fork();

    if(c1Pid == 0) {
      for (int i = 0; i < 1000000; i++) {
        fprintf(fp,"%d ",(int)(random() % 100));

      }
        printf("[CHILD1] Wrote 1000000 integers to numbers.txt, terminating.\n");

    } else {
        printf("[PARENT] Child process ID: %d\n", c1Pid);
        wait(NULL);

        c2Pid = fork();

        if(c2Pid == 0) {
          printf("[CHILD2]");
          while ( (fscanf(fr, "%d", &num) == 1) ) {
        if (num%2==0) {
      even++;
        }
      }printf("Even numbers:%d Odd numbers:%d\n",even,1000000-even );
        } else {
            printf("[PARENT] Child process ID: %d\n", c2Pid);
            wait(NULL);
            printf("[PARENT] Terminating.\n");
        }
    }
}
