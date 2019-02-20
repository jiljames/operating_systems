#include "bitset.h"

/*
Tests the basic functionality of the BitSet construction

*/

// checks getBit and setBit
void test_set_get(){
	BitSet* B = allocBitSet(64);
	setBit(B, 18);
	_Bool bit = getBit(B, 18);
	assert(bit);

}
// tests that clearing a bit clears it
void test_clear_bit(){
	BitSet* B = allocBitSet(64);
	setBit(B, 13);
	clearBit(B, 13);
	_Bool bit = getBit(B, 13);
	assert(bit==0);
}

// tests that allocating too many items returns an error
// but until then, no errors
void test_over_flow(){
	int result;
	BitSet* B = allocBitSet(8);
	for(int i = 0; i<8; i++){
		result = allocItem(B);
		assert(result != -1); // tests no errors
	}
	//buffer full now
	result = allocItem(B);
	assert(result==-1); //tests error

}

// tests that a freed item is freed and 
// may be allocated again
void test_free_item(){
	int result;
	BitSet* B = allocBitSet(8);
	for(int i = 0; i<8; i++){
		result = allocItem(B);
		assert(result != -1); // test no errors
	}
	//buffer full now
	freeItem(B, 3);
	//one space open
	_Bool freed_item = getBit(B, 3);
	//full again
	result = allocItem(B);
	_Bool allocated_item = getBit(B, 3);
	assert(freed_item==0 && allocated_item==1 && result==3);

}

// tests that read and write work on a 64-bit bitset
void test_read_write(){
	BitSet* B3 = allocBitSet(64);
	setBit(B3, 3);
	setBit(B3, 37);
	setBit(B3, 39);
	writeBitSet("test3.txt", B3);
	BitSet* B3Hold = allocBitSet(64);
	readBitSet("test3.txt", B3Hold);
	assert(strcmp(B3->bits, B3Hold->bits) == 0);
}


int main() {
	test_clear_bit();
	test_set_get();
	test_over_flow();
	test_free_item();
	test_read_write();
	printf("🙃🙃🙃 All tests passed! 🙃🙃🙃\n");
	return 0;
}