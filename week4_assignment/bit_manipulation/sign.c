#include<stdio.h>
#include <stdlib.h>
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 *  return ((!!x) | (x >> 31));
 */
int sign(int x) {
  int negative = x >> 31;
  int positive = !!x;

  return negative | positive;
}

int main() {
    int x;
    printf("Enter an integer (x): ");
    scanf("%d", &x);

    int result = sign(x);
    printf("sign(%d) = %d\n", x, result);

    return 0;
}