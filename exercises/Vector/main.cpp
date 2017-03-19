#include <iostream>
#include "Vector.hpp"
#include "Vector(bool).hpp"


using namespace sns;

int main() {

    /*Vector<double> arr0(10);
    Vector<double> arr1(10);
    arr0[0] = 1.1;
    std::cout << "arr0[0] = " << arr0[0] << std::endl;

    arr1[1] = arr0[0];

    std::cout << "arr1[1] = " << arr1[1] << std::endl;*/

    Vector<bool> someVec(10);
    std::cout << "1  --------------------------------" << std::endl;
    someVec[1] = 1;
    std::cout << "2  --------------------------------" << std::endl;
    someVec[2] = someVec[1];
    std::cout << "3  --------------------------------" << std::endl;



    for (size_t i = 0; i != 10; ++i)
    {
    	std::cout << someVec[i];
    }
    std::cout << std::endl;
}