
/* 
Jillian James and Marika Swanberg's Bitset Implementation
Note: Our implementation assumes that the bitsets 
have a multiple of eight bits. 

TO COMPILE with tests, run:
gcc bitset.h bitset.c tests.c -o tests

(see our main() function in tests.c)
*/



#include "bitset.h"

typedef u_int8_t uint8_t;
//allocates and returns a pointer to a BitSet
BitSet* allocBitSet(int num_bits){
	if ((num_bits <= 0) && (num_bits % 8 != 0)) {
		printf("Bad Input");
	}
	BitSet* bitpointer = malloc(sizeof(char*)+sizeof(int)); //malloc a bitset
	bitpointer->bits = malloc(sizeof(char)*num_bits/8); //malloc for the bit array
	memset(bitpointer->bits, 0, num_bits/8);
	bitpointer->bits_len = num_bits; //set length of bits
	return bitpointer;
}

uint8_t mask(int i){
	int bit_pos = i%8;
	uint8_t mask = 1 << bit_pos;
	return mask;
}

// sets bit i of the BitSet
void setBit(BitSet* b, int i){
	uint8_t mask_for_i = mask(i);
	b->bits[i/8] = (mask_for_i | b->bits[i/8]);

}

// clears bit i of the BitSet
void clearBit(BitSet* b, int i){
	uint8_t mask_for_i = ~mask(i);
	b->bits[i/8] = mask_for_i & b->bits[i/8];
}


//returns the bit (boolean) value of the ith bit of the BitSet
_Bool getBit(BitSet* b, int i){
	uint8_t mask_for_i = mask(i);
	if ((mask_for_i & b->bits[i/8]) == 0) {
		return 0;
	} else {
		return 1;
	}
}


// returns the index of an item that was free, but is now allocated. If there are no more free items, returns a negative number
int allocItem(BitSet* b){
	for (int i = 0; i < b->bits_len; i++){
		if (getBit(b, i) == 0){
			setBit(b,i);
			return i;
		}
		
	} return -1;
}


// frees the item at location i, first checking that it wasn't already free.
int freeItem(BitSet* b, int i){
	if (getBit(b,i) == 1) {
		clearBit(b,i);
		return 0;
	} else {
		return -1;
	}
}


//reads, from file f, a Bit Set into the memory pointed to by b.
void readBitSet(char* filename, BitSet* b){
	FILE* ptr = fopen(filename, "r");
	fseek(ptr, 0L, SEEK_END);
	int length = ftell(ptr);
	rewind(ptr);
	b->bits = malloc(sizeof(char)*length);
	fread(b->bits, sizeof(char), length, ptr);
	fclose(ptr);
	b->bits_len = length*8;
}


//writes Bit Set b to file f
void writeBitSet(char* filename, BitSet *b){
	FILE* ptr = fopen(filename, "w");
	fwrite(b->bits, (b->bits_len)/8, sizeof(char), ptr);
	fclose(ptr);
}

void print_bitz(BitSet* b){
	_Bool bitz;
	for(int i=0; i<(b->bits_len); i++){
		bitz = getBit(b, i);
		printf("%d", bitz);
	}
	printf("\n");
}

// int main(){

// //Tests!!!

// 	//Test 1:
// 	BitSet* B = allocateBitSet(8);
// 	setBit(B, 1);
// 	writeBitSet("test1.txt", B);
// 	setBit(B, 2);
// 	writeBitSet("test2.txt", B);
// 	assert()



// 	return 0;
// }


