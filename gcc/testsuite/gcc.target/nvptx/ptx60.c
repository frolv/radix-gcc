/* { dg-do compile } */
/* { dg-options "-march=sm_30 -mptx=6.0" } */

#if __PTX_ISA_VERSION_MAJOR__ != 6
#error wrong value for __PTX_ISA_VERSION_MAJOR__
#endif

#if __PTX_ISA_VERSION_MINOR__ != 0
#error wrong value for __PTX_ISA_VERSION_MINOR__
#endif
