#include "funcs.h"
#include "stdint.h"










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









inline int getLowestIndex(uint64_t x){
  const uint64_t m0 = 0xAAAAAAAAAAAAAAAA;
  const uint64_t m1 = 0xCCCCCCCCCCCCCCCC;
  const uint64_t m2 = 0xf0f0f0f0f0f0f0f0;
  const uint64_t m3 = 0xff00ff00ff00ff00;
  const uint64_t m4 = 0xffff0000ffff0000;
  const uint64_t m5 = 0xffffffff00000000;

  uint64_t bit = x & (~x + 1);  // isolate lowest bit

  // compute index
  uint64_t acum= 0;
  acum |= (bit & m0)?  1 : 0;
  acum |= (bit & m1)?  2 : 0;
  acum |= (bit & m2)?  4 : 0;
  acum |= (bit & m3)?  8 : 0;
  acum |= (bit & m4)? 16 : 0;
  acum |= (bit & m5)? 32 : 0;

  return acum;
}










inline void seedRand(int seed){
  randstate = seed;
  if(!(seed % 2)){
    randstate++;
  }
}










inline int8_t fastRand(){
  randstate = (135976497283641 * randstate) + 135761793679;
  return (int8_t)(((randstate / 64) % 256) - 128);
}
