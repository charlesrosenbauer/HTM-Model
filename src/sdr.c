#include "sdr.h"
#include "stdint.h"
#include "stdlib.h"










inline SDR256 sdr256_union       (SDR256 a, SDR256 b){
  SDR256 ret;
  ret.bits[0] = a.bits[0] | b.bits[0];
  ret.bits[1] = a.bits[1] | b.bits[1];
  ret.bits[2] = a.bits[2] | b.bits[2];
  ret.bits[3] = a.bits[3] | b.bits[3];
  return ret;
}










inline SDR256 sdr256_intersection(SDR256 a, SDR256 b){
  SDR256 ret;
  ret.bits[0] = a.bits[0] & b.bits[0];
  ret.bits[1] = a.bits[1] & b.bits[1];
  ret.bits[2] = a.bits[2] & b.bits[2];
  ret.bits[3] = a.bits[3] & b.bits[3];
  return ret;
}









BigSDR bigsdr_union       (BigSDR a, BigSDR b){
  int maxsize, minsize;

  if(a.size < b.size){
    maxsize = b.size;
    minsize = a.size;
  }else{
    maxsize = a.size;
    minsize = b.size;
  }

  BigSDR ret = bigsdr_make(maxsize);

  for(int i = 0; i < minsize; i++){
    ret.chunks[i] = sdr256_union(a.chunks[i], b.chunks[i]);
  }
  if(a.size < b.size){
    for(int i = minsize; i < maxsize; i++)
      ret.chunks[i] = b.chunks[i];
  }else{
    for(int i = minsize; i < maxsize; i++)
      ret.chunks[i] = a.chunks[i];
  }

  return ret;
}










BigSDR bigsdr_intersection(BigSDR a, BigSDR b){
  int maxsize, minsize;

  if(a.size < b.size){
    maxsize = b.size;
    minsize = a.size;
  }else{
    maxsize = a.size;
    minsize = b.size;
  }

  BigSDR ret = bigsdr_make(maxsize);

  for(int i = 0; i < minsize; i++){
    ret.chunks[i] = sdr256_intersection(a.chunks[i], b.chunks[i]);
  }
  if(a.size < b.size){
    for(int i = minsize; i < maxsize; i++)
      ret.chunks[i] = b.chunks[i];
  }else{
    for(int i = minsize; i < maxsize; i++)
      ret.chunks[i] = a.chunks[i];
  }

  return ret;
}










BigSDR bigsdr_make        (int size){
  BigSDR ret;
  ret.size = size;
  ret.chunks = malloc(sizeof(SDR256) * size);
  return ret;
}
