//---------------------------------------------
//! @IDE CLion
//! @file main.cpp
//! Empty test file
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#define NDEBUG

#include <iostream>
#include <string>
#include "Processor.h"



using namespace cpuns;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Memory path was no set." << std::endl;
        return 1;
    }
    std::string path(argv[1]);

    while(1)
    {
        try
        {
            Processor<unsigned> proc(256, 32);
            if(proc.fillMemory(path) == false)
            {
                throw std::runtime_error("Failed open file with memory. Used path: " + path);
            }

            for (size_t i = 0; i < 32; ++i)
            {
                std::cout << std::dec << "Reg[" << i << "] = " << std::hex << proc.getRegValue(i) << "." << std::endl;
            }

            char runResult = proc.run();
            if(runResult == OUT_OF_MEM_RANGE)
            {
                throw std::out_of_range("Out of memory range.");
            }
            else if(runResult == STACK_UNDERFLOW)
            {
                throw std::underflow_error("Stack undeflow.");
            }
            else if(runResult == SUCCESS)
            {   
                std::cout << "Success!" << std::endl;
                return 0;
            }
            else
            {
                throw std::runtime_error("Unexpected failed");
            }
        }
        catch(std::out_of_range &exc)
        {
            exc.what();
        }
        catch(std::runtime_error &exc)
        {
            exc.what();
        }
        catch(std::underflow_error &exc)
        {
            exc.what();
        }
        catch(std::exception &exc)
        {   
            exc.what();
            return 1;
        }
    }
}
