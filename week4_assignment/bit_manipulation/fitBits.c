#include <stdio.h>
#include <stdlib.h>
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  return !((x >> (n + ~0)) ^ (x >> 31));
}

int main() {
    int x, n;
    printf("Enter an integer (x) and the number of bits (n): ");
    scanf("%d %d", &x, &n);

    if (n < 1 || n > 32) {
        printf("Error: n must be between 1 and 32.\n");
        return 1;
    }

    int result = fitsBits(x, n);
    printf("fitsBits(%d, %d) = %d\n", x, n, result);

    return 0;
}