//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef HEADERFILE_H
#define HEADERFILE_H

typedef struct BitSet{
	char* bits;
	int bits_len;
} BitSet, *BitSet_p;

//allocates and returns a pointer to a BitSet
BitSet* allocBitSet(int num_bits);



// sets bit i of the BitSet
void setBit(BitSet* b, int i);


// clears bit i of the BitSet
void clearBit(BitSet* b, int i);

//returns the bit (boolean) value of the ith bit of the BitSet
_Bool getBit(BitSet* b, int i);


// returns the index of an item that was free, but is now allocated. If there are no more free items, returns a negative number
int allocItem(BitSet* b);



// frees the item at location i, first checking that it wasn't already free.
int freeItem(BitSet* b, int i);


//reads, from file f, a Bit Set into the memory pointed to by b.
void readBitSet(char* filename, BitSet* b);



//writes Bit Set b to file f
void writeBitSet(char* filename, BitSet* b);

// prints bitset to terminal for debugging
void print_bitz(BitSet* b);

#endif

