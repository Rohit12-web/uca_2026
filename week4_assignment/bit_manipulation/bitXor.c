#include <stdio.h>
#include <stdlib.h>
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~x & ~y) & ~(x & y);
}

int main() {
    int x, y;
    printf("Enter two integers (x and y): ");
    scanf("%d %d", &x, &y);

    int result = bitXor(x, y);
    printf("bitXor(%d, %d) = %d\n", x, y, result);

    return 0;
}