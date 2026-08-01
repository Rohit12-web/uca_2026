#include <stdio.h>
#include <stdlib.h>
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    int mask = !!x; // 1 if x is non-zero, 0 if x is zero
    mask = ~mask + 1; // -1 (all bits 1) if x is non-zero, 0 if x is zero
    return (y & mask) | (z & ~mask);
  
}

int main() {
    int x, y, z;
    printf("Enter three integers (x, y, z): ");
    scanf("%d %d %d", &x, &y, &z);

    int result = conditional(x, y, z);
    printf("conditional(%d, %d, %d) = %d\n", x, y, z, result);

    return 0;
}