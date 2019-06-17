#include "unittest.h"
#include "Binary.h"
#include <iostream>

int main()
{
	// TESTING FOR BITWISE.
	//char* output = nullptr;
	//output = Binary::dec_to_bin(629);

	//for (size_t index = 0; index < 32; index++)
	//{
	//	if (index % 4 == 0)
	//		std::cout << " ";

	//	std::cout << output[index];
	//}

	//char binary[33] = { "00000000000000000000000000001111" };

	//int dec = Binary::bin_to_dec(binary);

	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;

	return 0;
}