//gcc q1.c -o q1 -lpthread
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[10];
//static int a=9999;


void* doTheThing(void *i)
{
  int array[1000];
  int counter=0;
  int b=0;


for (int i = 0; i < 1000; i++) {
  array[i]=(rand () % 8999)+1000;
  counter=0;
  for(int z=2; z<array[i]; z++){
    if(array[i]%z == 0)
      counter=1;
}
if (counter==0) {
  b++;
}}

	printf("Prime:%d\n",b);

	return NULL;
}

int main(void)
{
srand((unsigned)time(NULL));
    int i = 0;
    int err;


    while(i < 10)
    {
        err = pthread_create(&(tid[i]), NULL, &doTheThing, (void*) (intptr_t) i);
 	if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
        printf("%d.Thread-",i+1);
        pthread_join(tid[i],NULL);
        i++;



    }


    return 0;
}
