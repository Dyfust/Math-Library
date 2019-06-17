#include <iostream>

namespace Binary
{
	char* dec_to_bin(int value) 
	{
		char* binary_string = new char[32]{ '0' };

		for (size_t i = 0; i < 32; i++)
		{
			if (((1 << i) & value) > 0)
			{
				binary_string[31 - i] = '1';
			}
			else
			{
				binary_string[31 - i] = '0';
			}
		}

		return binary_string;
	}

	int bin_to_dec(const char binary_string[32])
	{
		int dec = 0; // All 32 bits will be off.

		for (size_t i = 0; i < 32; i++)
		{
			if (binary_string[31 - i] == '1')
			{
				dec = ((1 << i) | dec);
			}	
		}

		return dec;
	}
}