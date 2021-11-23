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

int main() {
  int *second=(int *)10000;
   srand((unsigned)time(NULL));
   signal(SIGINT, signl);
int number= (rand() % 100)+100;

while (1)   {
  if (changer==0){
  printf("%d\n",number );
  number=number+10;
  sleep(1);
  if (number>200)
  exit(1);}
  if (changer==1){
  printf("%d\n",number );
  number=number-10;
  sleep(1);}
  if (number<100)
  exit(1);
}

    return 0;
}

void signl() {
  if (changer==0){
    printf("\n[DECREASE]\n");
    changer=1;
  }
  else {
    printf("\n[INCREASE]\n");
    changer=0;
  }
}
