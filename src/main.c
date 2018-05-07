#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"
#include "sdr.h"
#include "dendrite.h"
#include "funcs.h"










int main(){
  seedRand(51713531);

  Dendrite d;
  randDendrite(&d);
  showDendrite(&d);
}
