#include <stdio.h>

long long optimizedFibonacciEvenSum(long long n){
	long long even1 = 2;
	long long even2 = 8;
	long long evenSum = 0;

	while(even1 <= n){
	     evenSum += even1;
	     long long next = 4 * even2 + even1;

	     even1 = even2;
	     even2 = next;
	}

	return evenSum;
}

int main(){
	long long n;
	printf("Enter n: ");
	scanf("%lld", &n);
	printf("Even Sum = %lld\n", optimizedFibonacciEvenSum(n));

	return 0;
}
