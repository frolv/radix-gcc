/* { dg-options "-O3" } */

#include <stdint.h>

void __attribute ((noipa))
foo (uint32_t *__restrict x, uint32_t *__restrict y, int n)
{
  for (int i = 0; i < n; i += 4)
    {
      x[i] += y[i];
      x[i + 1] += y[i + 1];
      x[i + 2] |= y[i + 2];
      x[i + 3] |= y[i + 3];
    }
}

/* { dg-final { scan-assembler-times {\tld4w\t} 2 } } */
/* { dg-final { scan-assembler-times {\tst4w\t} 1 } } */
