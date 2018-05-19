#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"
#include "sdr.h"
#include "dendrite.h"
#include "funcs.h"










int main(){
  seedRand(51713531);

  Dendrite d, e;
  randDendrite(&d);
  randDendrite(&e);
  SDR256 s = toSDR(&e);
  showDendrite(&d);

  for(int i = 0; i < 2; i++){
    learn(&d, s, 1);
  }

  showDendrite(&d);
}
