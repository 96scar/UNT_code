#include "Set.h"	


void add(int i)
{
     // here is my add method --- I hope it works 'cause I ain't testing it.

     unsigned int mask;
     int bit, word;

     word = i / 32;    // find out which work of the bitstring array 
                       // contains "bit" i
     bit = i % 32;     // and which bit IN word, is the ith bit

     mask = 1 << bit;

     bitString[word] |= mask;
                       
}

