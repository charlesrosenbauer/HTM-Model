#ifndef __SDR_HEADER__
#define __SDR_HEADER__

#include "stdint.h"










typedef struct{
  uint64_t bits[4];
}SDR256;










typedef struct{
  SDR256* chunks;
  int size;
}BigSDR;










SDR256 sdr256_union       (SDR256, SDR256);
SDR256 sdr256_intersection(SDR256, SDR256);

BigSDR bigsdr_union       (BigSDR, BigSDR);
BigSDR bigsdr_intersection(BigSDR, BigSDR);

BigSDR bigsdr_make        (int);


#endif
