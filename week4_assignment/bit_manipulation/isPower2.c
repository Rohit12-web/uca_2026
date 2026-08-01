#include <stdio.h>
#include <stdlib.h>     
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
    int nonZero = !!x;           // 1 if x != 0
    int positive = !(x >> 31);   // 1 if x is not negative
    int oneBit = !(x & (x + ~0)); // 1 if x has exactly one set bit

    return nonZero & positive & oneBit;
}
int main() {
    int x;
    printf("Enter an integer (x): ");
    scanf("%d", &x);

    int result = isPower2(x);
    printf("isPower2(%d) = %d\n", x, result);

    return 0;
}