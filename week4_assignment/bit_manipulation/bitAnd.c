#include <stdio.h>
#include <stdlib.h>
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
}

int main() {
    int x, y;
    printf("Enter two integers (x and y): ");
    scanf("%d %d", &x, &y);

    int result = bitAnd(x, y);
    printf("bitAnd(%d, %d) = %d\n", x, y, result);

    return 0;
}   