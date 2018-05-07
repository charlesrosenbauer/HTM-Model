#ifndef __FUNCS_HEADER__
#define __FUNCS_HEADER__

#include "stdint.h"










static int randstate = 0;


int    popcount      (uint64_t);
int    getLowestIndex(uint64_t);
void   seedRand      (int);
int8_t fastRand      ();






#endif
