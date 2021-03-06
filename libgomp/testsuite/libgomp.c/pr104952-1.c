#define N 32

static char arr[N];

int
main (void)
{
  unsigned int result = 0;

  for (unsigned int i = 0; i < N; ++i)
    arr[i] = 0;

  arr[5] = 42;

#pragma omp target map(tofrom:result) map(to:arr)
#pragma omp simd reduction(||: result)
  for (unsigned int i = 0; i < N; ++i)
    result = result || arr[i];

  if (result != 1)
    __builtin_abort ();

  return 0;
}
