//type gcc q6.c -o q6 -lpthread
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[10];
int a=49999;
int array[49999];
char st[] = "abcdefghijklmnopqrstuvwxyz";
void* doTheThing(void *i)
{
    int  doubler = (intptr_t) i;

    char st_vowel[]="aeiou";
    int e;
    int counter=0;
    int b=0;
    int j = 0;
    int number_of_vowel=0;
    int number_of_consonants;
    pthread_t id = pthread_self();


    for(e=(doubler*10000); e<=(doubler*10000+(9999)); e++){
	char c = st[rand() % 26];

	if(c==st_vowel[0]){
	number_of_vowel++; }
	if(c==st_vowel[1]){
	number_of_vowel++; }
	if(c==st_vowel[2]){
	number_of_vowel++; }
	if(c==st_vowel[3]){
	number_of_vowel++; }
	if(c==st_vowel[4]){
	number_of_vowel++; }

			  }

	number_of_consonants=5000-number_of_vowel;
	printf("Thread %d found; Vowels:%d, Consonants:%d on its own one tenth.\n",doubler,number_of_vowel,number_of_consonants);

	pthread_equal(id,tid[0]);

	return NULL;
}

int main(void)
{

    srand((unsigned)time(NULL));
    int i = 1;
    int err;
    int e;
    for(e=0; e<=a; e++){
	char c = st[rand() % 26];  }

    while(i < 11)
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
