#include <iostream>
#include "Vector.hpp"



using namespace sns;

int main() {

    /*Vector<double> arr0(10);
    Vector<double> arr1(10);
    arr0[0] = 1.1;
    std::cout << "arr0[0] = " << arr0[0] << std::endl;

    arr1[1] = arr0[0];

    std::cout << "arr1[1] = " << arr1[1] << std::endl;*/

     Vector<bool> someVec(10);
     Vector<bool> otherVec(88);
     std::cout << "1  --------------------------------" << std::endl;
     someVec[1] = 1;
     std::cout << "2  --------------------------------" << std::endl;
     someVec[2] = someVec[1];
     std::cout << "3  --------------------------------" << std::endl;
     someVec[4] = someVec[2] = someVec[0] =  someVec[1];
     std::cout << "4  --------------------------------" << std::endl;
     someVec[3] = someVec[9] = someVec[8] = someVec[7] = someVec[6] = someVec[5] = 0;
     otherVec[75] = someVec[1];
     otherVec[87] = someVec[1];
     otherVec[0] = someVec[1];
     otherVec[31] = someVec[1];
     otherVec[32] = someVec[1];
     otherVec[32] = someVec[1];



     for (size_t i = 0; i != 10; ++i)
     {
         std::cout << "[" << i << "] = " << someVec[i] << ";" << std::endl;
     }
     std::cout << std::endl;
     std::cout << "5  --------------------------------" << std::endl;
     for (size_t i = 0; i != 88; ++i)
     {
         std::cout << "[" << i << "] = " << otherVec[i] << ";" << std::endl;
     }
}