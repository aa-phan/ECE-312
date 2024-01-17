#include <stdio.h>
#include <stdlib.h>

int count;
int sum;
int bound;

int isPrime(int num)
{
	if (num <= 1) return 0;
	if (num % 2 == 0 && num > 2) return 0;
	for(int i = 3; i< num / 2; i+= 2)
	{
		if( num % i == 0 ){
			return 0;
		}
	}
	return 1;
}

void findSum(int* bound, int* count, int* sum)
{
	/*Do something to detect if the number is prime */
	/*Modify the count and sum accordingly*/
	/* Start your code here */
    int i = 0;
    while(i<*bound){
        if(isPrime(i)==1){
            *count+=1;
            *sum+=i;

        }
        i++;
    }
}


int main()
{
	bound = 0;
	count = 0;
	sum = 0;
	printf("Please indicate the boundary of your search: \n");
	scanf("%d", &bound);
	findSum(&bound, &count, &sum);
	printf("The sum of the prime numbers up to %d is %d\n",bound, sum);
	return 0;
}

