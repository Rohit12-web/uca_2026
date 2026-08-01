#include <stdio.h>
#include <stdlib.h>
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

int main() {
    int x, n;

    printf("Enter a hexadecimal integer (x) and shift amount (n): ");

    if (scanf("%x %d", &x, &n) != 2) {
        printf("Invalid input!\n");
        return 1;
    }

    if (n < 0 || n > 31) {
        printf("Error: n must be between 0 and 31.\n");
        return 1;
    }

    int result = logicalShift(x, n);

    printf("logicalShift(0x%X, %d) = 0x%X\n", x, n, result);

    return 0;
}