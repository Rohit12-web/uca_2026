#include <stdio.h>
#include <stdlib.h> 
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  return (x >> (n << 3)) & 0xFF;
}

int main() {
    int x, n;
    printf("Enter an integer (x) and the byte position (n): ");
    scanf("%x %d", &x, &n);

    if (n < 0 || n > 3) {
        printf("Error: n must be between 0 and 3.\n");
        return 1;
    }

    int result = getByte(x, n);
    printf("getByte(0x%X, %d) = 0x%X\n", x, n, result);

    return 0;
}