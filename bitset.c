//includes
#include "bitset.h"



typedef struct BitSet{
	char* bits;
	int bits_len;
} BitSet, *BitSet_p;

//allocates and returns a pointer to a BitSet
BitSet* allocateBitSet(int num_bits){
	if ((num_bits <= 0) && (num_bits % 8 != 0)) {
		printf("Bad Input");
	}

	BitSet* bitpointer = malloc((num_bits/8)*sizeof(char));
	return bitpointer;
}

char mask(Bitset* b, position i){
	num_byte = i/25;
	bit_pos = i%8;
	char mask = 1 << bit_pos;
	return mask
}

// sets bit i of the BitSet
void setBit(BitSet* b, int i){



}

// clears bit i of the BitSet
int clearBit(BitSet* b, int i){
	b[i] = 0;
	return 0;
}


//returns the bit (boolean) value of the ith bit of the BitSet
_Bool getBit(BitSet* b, int i){
	return b[i]
}


// returns the index of an item that was free, but is now allocated. If there are no more free items, returns a negative number
int allocItem(BitSet* b){
	for (i = 0; b[i] == NULL; i++){
		if (b[i] == 0){
			setBit(b,i);
			return i
		}
	} return -1
}



// frees the item at location i, first checking that it wasn't already free.
int freeItem(BitSet b, int i){
	if (b[i] == 0) {
		return -1;
	} else {
		return clearBit(b,i);
	}
}



//reads, from file f, a Bit Set into the memory pointed to by b.
void readBitSet(FILE f, BitSet* b){

}



//writes Bit Set b to file f
void writeBitSet(FILE f, BitSet *b){}