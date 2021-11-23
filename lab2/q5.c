#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void signl();
static int input = 0 ;
static int changer;
static int number;

int main() {

   srand((unsigned)time(NULL));
   signal(SIGINT, signl);
int counter=0;

while (1)   {
  if (changer==0){
    int number= (rand() % 9)+1;
    printf("%d\n",number );
  sleep(1);
counter++;
if (counter >15 )
exit(1); }
  if (changer==1){
  char st[] = "abcdefghijklmnopqrstuvwxyz";
  printf("%c\n",st[(rand() % 26)] );
  sleep(1);
  counter++;
if (counter >15 )
exit(1);
{
  /* code */
}}
}

    return 0;
}

void signl() {
  if (changer==0){
    printf("\n");
    changer=1;
  }
  else {
    printf("\n");
    changer=0;
  }
}

/*
rumeysa@rumeysa-VirtualBox:~/Desktop/lab2$ gcc q5.c -o q5
rumeysa@rumeysa-VirtualBox:~/Desktop/lab2$ ./q5
1
8
6
8
5
6
4
1
3
7
7
9
9
2
4
9
rumeysa@rumeysa-VirtualBox:~/Desktop/lab2$ 
*/
