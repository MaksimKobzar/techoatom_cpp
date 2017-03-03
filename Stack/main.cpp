//---------------------------------------------
//! @IDE CLion
//! @file main.cpp
//! Empty test file
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include "Stack.hpp"

//int main(int argc, char** argv)
//{
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
//}
using namespace sns;

int main() {
    Stack<double> stack1(10);
    Stack<double> stack2(10);

    std::cout << "All right!" << std::endl;
}