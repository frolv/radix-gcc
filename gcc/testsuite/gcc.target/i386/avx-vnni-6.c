/* { dg-do compile } */
/* { dg-options "-mavxvnni -O2" } */
/* { dg-final { scan-assembler-times "\{vex\} vpdpbusd\[ \\t\]+\[^\{\n\]*%ymm\[0-9\]+\[^\n\r]*%ymm\[0-9\]+\[^\n\r]*%ymm\[0-9\]+(?:\n|\[ \\t\]+#)" 1 } } */
/* { dg-final { scan-assembler-times "\{vex\} vpdpbusd\[ \\t\]+\[^\{\n\]*%xmm\[0-9\]+\[^\n\r]*%xmm\[0-9\]+\[^\n\r]*%xmm\[0-9\]+(?:\n|\[ \\t\]+#)" 1 } } */
/* { dg-final { scan-assembler-times "\{vex\} vpdpbusds\[ \\t\]+\[^\{\n\]*%ymm\[0-9\]+\[^\n\r]*%ymm\[0-9\]+\[^\n\r]*%ymm\[0-9\]+(?:\n|\[ \\t\]+#)" 1 } } */
/* { dg-final { scan-assembler-times "\{vex\} vpdpbusds\[ \\t\]+\[^\{\n\]*%xmm\[0-9\]+\[^\n\r]*%xmm\[0-9\]+\[^\n\r]*%xmm\[0-9\]+(?:\n|\[ \\t\]+#)" 1 } } */
/* { dg-final { scan-assembler-times "\{vex\} vpdpwssd\[ \\t\]+\[^\{\n\]*%ymm\[0-9\]+\[^\n\r]*%ymm\[0-9\]+\[^\n\r]*%ymm\[0-9\]+(?:\n|\[ \\t\]+#)" 1 } } */
/* { dg-final { scan-assembler-times "\{vex\} vpdpwssd\[ \\t\]+\[^\{\n\]*%xmm\[0-9\]+\[^\n\r]*%xmm\[0-9\]+\[^\n\r]*%xmm\[0-9\]+(?:\n|\[ \\t\]+#)" 1 } } */
/* { dg-final { scan-assembler-times "\{vex\} vpdpwssds\[ \\t\]+\[^\{\n\]*%ymm\[0-9\]+\[^\n\r]*%ymm\[0-9\]+\[^\n\r]*%ymm\[0-9\]+(?:\n|\[ \\t\]+#)" 1 } } */
/* { dg-final { scan-assembler-times "\{vex\} vpdpwssds\[ \\t\]+\[^\{\n\]*%xmm\[0-9\]+\[^\n\r]*%xmm\[0-9\]+\[^\n\r]*%xmm\[0-9\]+(?:\n|\[ \\t\]+#)" 1 } } */


#include <immintrin.h>

volatile __m256i x,y,z;
volatile __m128i x_,y_,z_;

void extern
avxvnni_test (void)
{
  x = _mm256_dpbusd_avx_epi32 (x, y, z);
  x_ = _mm_dpbusd_avx_epi32 (x_, y_, z_);
  x = _mm256_dpbusds_avx_epi32 (x, y, z);
  x_ = _mm_dpbusds_avx_epi32 (x_, y_, z_);
  x = _mm256_dpwssd_avx_epi32 (x, y, z);
  x_ = _mm_dpwssd_avx_epi32 (x_, y_, z_);
  x = _mm256_dpwssds_avx_epi32 (x, y, z);
  x_ = _mm_dpwssds_avx_epi32 (x_, y_, z_);
}
