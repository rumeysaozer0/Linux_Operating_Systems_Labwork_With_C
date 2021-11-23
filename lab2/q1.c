#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signl();

static int input = 0;
static int Sum = 0;
static int Counter = 0;

int main() {
	signal(SIGINT, signl);

	while (1) {
	printf("Enter a number:");
	scanf("%d", &input);

	if(input == -1){
		exit(0);
}
		Sum += input;
		Counter++;
	}

	return 0;
}
void signl() {
	printf("\nInputs: %d", Counter);
	printf("\nAverage: %.2f\n",(float) Sum / Counter);
	Sum = 0;
	Counter =  0;
}

/*
rumeysa@rumeysa-VirtualBox:~/Desktop/lab2$ gcc q1.c -o q1
rumeysa@rumeysa-VirtualBox:~/Desktop/lab2$ ./q1
Enter a number:100
Enter a number:200
Enter a number:300
Enter a number:400
Enter a number:^C
Inputs: 4
Average: 250.00



 
*/
