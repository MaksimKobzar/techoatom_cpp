#include <iostream>
#include "Vector.hpp"


using namespace sns;

int main() {

    Vector<double> arr0(10);
    Vector<double> arr1(10);
    arr0[0] = 1.1;
    std::cout << "arr0[0] = " << arr0[0] << std::endl;
    arr1 = arr0;
    std::cout << "arr1[0] = " << arr1[0] << std::endl;
    arr1[1] = arr0[0];
    std::cout << "arr1[1] = " << arr1[1] << std::endl;
}