//type gcc q4.c -o q4 -lpthread
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[10];
//static int a=9999;
 int array[10000];


void* doTheThing(void *i)
{
    int  t_n = (intptr_t) i;
    int z,j,e,s;
    int counter=0;
    int oned,twod,threed,fourd,fived;
    int b=0;

    pthread_t id = pthread_self();

	oned=0;
	twod=0;
	threed=0;
	fourd=0;
	fived=0;
	for(z=(t_n*2000);z<(t_n*2000)+1999;z++)
     {
           s=array[z];
	counter=0;

        while(s != 0)
    {
 	++counter;
        s /= 10;

    }
	if(counter ==1){
	oned++;	}

	if(counter ==2){
	twod++;	}

	if(counter ==3){
	threed++; }

	if(counter ==4){
	fourd++; }

	if(counter ==5){
	fived++; }
     }

	printf("%d. Thread: 1-9: %d, 10-99: %d, 100-999: %d, 1000-9999: %d, 10000-49999: %d (on its own one fifth) \n",(t_n+1),oned,twod,threed,fourd,fived);

	pthread_equal(id,tid[0]);

	return NULL;
}

int main(void)
{
srand((unsigned)time(NULL));
    int e;
    int i = 0;
    int err;

 for(e=0; e<10000; e++){

	int n = (rand() % 50000);
    	array[e]=n;
}
      while(i <= 4)
    {
        err = pthread_create(&(tid[i]), NULL, &doTheThing, (void*) (intptr_t) i);
 	if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
          pthread_join(tid[i],NULL);

        i++;



    }

    return 0;
}
