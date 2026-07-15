#include <stdio.h>

long long bruteForce(long long n){
    long long a = 1;
    long long b = 1;
    long long sum = 0;

    while (b <= n){
        if (b % 2 == 0){
            sum += b;
        }

        long long next = a + b;

        a = b;
        b = next;
    }

    return sum;
}

long long optimized(long long n){
    long long sum = 0;

    long long even1 = 2;
    long long even2 = 8;

    while (even1 <= n){
        sum += even1;

        long long next = 4 * even2 + even1;

        even1 = even2;
        even2 = next;
    }

    return sum;
}

int main(){
    long long n;

    printf("Enter n: ");
    scanf("%lld", &n);

    printf("Brute Force Sum = %lld\n", bruteForce(n));
    printf("Optimized Sum = %lld\n", optimized(n));

    return 0;
}
