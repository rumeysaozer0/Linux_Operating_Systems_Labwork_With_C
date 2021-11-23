//type gcc q2.c -o q2 -lpthread
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
	int  doubler = (intptr_t) i;
    int z,j;
    int counter=0;
    int b=0;

    pthread_t id = pthread_self();

	for(z=(doubler*1000);z<(doubler*1000)+999;z++)
     {
           counter=0;
           for(j=2;j<array[z];j++)
           {
                if(array[z]%j==0)
               {
                      counter=1;
                       break;
                 }
           }
           if(counter==0)
           {
		b++;
          }
    }

	printf(" Found %d prime number in its own one tenth\n",b);

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

	int n = (rand() % 8999)+  1000;
    	array[e]=n;
}
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
