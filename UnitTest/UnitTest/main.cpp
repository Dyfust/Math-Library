#include "unittest.h"
#include <iostream>

int main() {

	//Matrix3 lhs = Matrix3({ 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 });
	//Matrix3 rhs = Matrix3({ 1, 3, 2 }, { 1, 3, 2 }, { 2, 3, 1 });

	//Matrix3 result = lhs * rhs;

	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;

	return 0;
}