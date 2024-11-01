#include <stdio.h>

int setbits(int x, int p, int n, int y);
int invert(int x, int p, int n);
int rightrot(int x, int n);

int main() {
  int out = setbits(11, 1, 2, 3);
  printf("%d\n", out);

  int out2 = invert(11, 2, 3);
  printf("%d\n", out2);

  int out3 = rightrot(16, 2);
  printf("%d\n", out3);

  return 0;
}

// Ex. 2-6: Write a function setbits(x,p,n,y) that returns x with the n bits
// that begin at position p set to the rightmost n bits of y, leaving the other
// bits unchanged.

int setbits(int x, int p, int n, int y) {
  int nx = x;

  nx = nx >> (p + 1 - n); // shift to the rightmost bits at position put
  y = y & ~(~0 << n);     // set y to the rightmost n bits of y
  nx = nx & y;
  return nx;
}

// Ex. 2-7: Write a function invert(x,p,n) that returns x with the n bits that
// begin at position p inverted

int invert(int x, int p, int n) {
  int y = 0;
  y = ~(~0 << n);
  y = y << (p + 1 - n);

  return x ^ y;
}

// Ex. 2-8: Write a function rightrot(x,n) that returns the integer x rotated
// right n times

int rightrot(int x, int n) {
  for (int i = 0; i < n; i++) {
    if ((x & 1) == 1)
      x = (x >> 1) | ~(~0 >> 1);
    else
      x = (x >> 1);
  }

  return x;
}
