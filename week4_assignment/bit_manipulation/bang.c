#include <stdio.h>
#include <stdlib.h>
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 *   return ((x | (~x + 1)) >> 31) + 1;
 */
int bang(int x) {
    int negative = ~x + 1;
    int combined = x | negative;
    int sign = combined >> 31;

    return sign + 1;
}

int main() {
    int x;
    printf("Enter an integer (x): ");
    scanf("%d", &x);

    int result = bang(x);
    printf("bang(%d) = %d\n", x, result);

    return 0;
}