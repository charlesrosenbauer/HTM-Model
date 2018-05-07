#ifndef __DENDRITE_HEADER__
#define __DENDRITE_HEADER__

#include "sdr.h"
#include "stdint.h"










static const int SYNAPSETHRESHOLD = 3;










typedef struct{
  uint8_t pos[8];       // Positions of top 8 synapses
  uint8_t weights[4];   // Weights of top 8 synapses, each weight is 4 bits
}Dendrite;










SDR256 toSDR(Dendrite*);
int    match(Dendrite*, SDR256, int);
void   learn(Dendrite*, SDR256, int);












#endif
