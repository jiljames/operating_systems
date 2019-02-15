//includes
#include <stdio.h>
#include <stdlib.h>



typedef char* BitSet;

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
void freeItem(BitSet b, int i);


//reads, from file f, a Bit Set into the memory pointed to by b.
void readBitSet(FILE f, BitSet* b);



//writes Bit Set b to file f
void writeBitSet(FILE f, BitSet *b);