#include "dendrite.h"
#include "funcs.h"










inline SDR256 toSDR(Dendrite* d){
  SDR256 ret;
  for(int i = 0; i < 8; i++){
    int shift = 4 * (i % 2);
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










void learn(Dendrite* d, SDR256 sdr, int threshold){

  if(match(d, sdr, threshold)){

    int reassign = 0; // Boolean

    for(int i = 0; i < 8; i++){
      int shift = 4 * (i % 2);
      uint8_t weight = (d->weights[i/2] >> shift) & 0x0F;

      int bitindex = d->pos[i] / 64;
      int bitoffset= d->pos[i] % 64;

      if(sdr.bits[bitindex] & d->pos[bitindex] & (1 << bitoffset)){
        //Increase weight
        if(weight != 0x0F){
          weight++;
          d->weights[i/2] &= (0x00F0 >> shift);
          d->weights[i/2] |= (weight << shift);
        }
      }else{
        //Decrease weight, alert to reassigns
        if(weight != 0x00){
          weight--;
          d->weights[i/2] &= (0x00F0 >> shift);
          d->weights[i/2] |= (weight << shift);
        }else{
          reassign |= (1 << i);
        }
      }
    }

    // Are there synapses that need to be reassigned?
    if(reassign){

      SDR256 unusedBits;
      SDR256 dend = toSDR(d);   // Probably not efficient to recalculate this, but KISS for now.

      // Get bits that are in the input sdr, but not on the dendrite
      for(int i = 0; i < 4; i++)
        unusedBits.bits[i] = ~dend.bits[i] & sdr.bits[i];



      /*
        Not sure how I'll do this, but I need to
      */
    }
  }

  // If the SDR doesn't match the dendrite, no learning occurs.
  return;
}
