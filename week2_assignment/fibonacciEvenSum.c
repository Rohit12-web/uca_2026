#include <stdio.h>

long long fibonacciEvenSum(long long n){
	long long a = 1;
	long long b = 1;
	long long evenSum = 0;

	while(b <= n){
	    if(b %2 == 0){
		   evenSum += b;
	      }
	    
	    long long next = a + b;

	    a = b;
	    b = next;
	}

	return evenSum;
}

int main(){
    long long n;

    printf("Enter n: ");
    scanf("%lld", &n);
    printf("Even Sum = %lld\n", fibonacciEvenSum(n));

    return 0;
}

