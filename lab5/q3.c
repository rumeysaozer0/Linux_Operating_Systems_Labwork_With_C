//type gcc q3.c -o q3 -lpthread
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[5];
static int array[2000];

void* doTheThing(void *i)
{
int  t_n = (intptr_t) i;

    int a=1999;
    int z,j,e,s;
    int oned,twod,threed,fourd,fived;
    int counter;
    pthread_t id = pthread_self();

    for(e=0; e<=a; e++){

	int n = (rand() % 50000);
    	array[e]=n;
}
	oned=0;
	twod=0;
	threed=0;
	fourd=0;
	fived=0;
	for(z=0;z<=a;z++)
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

	printf(" %d. Thread: 1-9: %d, 10-99: %d, 100-999: %d, 1000-9999: %d, 10000-49999: %d  \n",t_n,oned,twod,threed,fourd,fived);

	pthread_equal(id,tid[0]);

	return NULL;
}

int main(void)
{
srand((unsigned)time(NULL));
    int i = 1;
    int err;

    while(i <= 5)
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
