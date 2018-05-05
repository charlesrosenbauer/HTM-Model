#ifndef __DENDRITE_HEADER__
#define __DENDRITE_HEADER__

#include "sdr.h"
#include "stdint.h"










typedef struct{
  uint8_t pos[8];       // Positions of top 8 synapses
  uint8_t weights[4];   // Weights of top 8 synapses, each weight is 4 bits
}Dendrite;










//SDR256   match(Dendrite, SDR256, int);
//Dendrite learn(Dendrite, SDR256, int);












#endif
