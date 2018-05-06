#include "dendrite.h"










inline int popcount(uint64_t x){
  const uint64_t m0 = 0x5555555555555555;
  const uint64_t m1 = 0x3333333333333333;
  const uint64_t m2 = 0x0f0f0f0f0f0f0f0f;
  const uint64_t m3 = 0x0101010101010101;

  x -= (x >> 1) & m0;
  x = (x & m1) + ((x >> 2) & m1);
  x = (x + (x >> 4)) & m2;
  return (x * m3) >> 56;
}










inline SDR256 toSDR(Dendrite* d){
  SDR256 ret;
  for(int i = 0; i < 8; i++){
    uint8_t shift = 4 * (i % 2);
    if((d->weights[i/2] >> shift) >= SYNAPSETHRESHOLD){
      int bitindex = d->pos[i] / 64;
      int bitoffset= d->pos[i] % 64;
      ret.bits[bitindex] |= (1 << bitoffset);
    }
  }
  return ret;
}










int match(Dendrite* d, SDR256 sdr, int threshold){
  SDR256 dend = toSDR(d);

  SDR256 inter= sdr256_intersection(dend, sdr);

  int count = popcount(inter.bits[0]) + popcount(inter.bits[1]) + popcount(inter.bits[2]) + popcount(inter.bits[3]);

  return count > threshold;
}
