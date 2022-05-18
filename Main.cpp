/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    csc232.h
 * @author  Daniel Abbott <dsa808@missouristate.edu>
 * @brief   Entry point of Final Lab Group Project
 */

#include "csc232.h"

int main()
{
#if EXECUTE_BLOCK
    std::cout << "Hello, Main!" << std::endl;
#endif
    
    Simulate("mainData.txt");
    return EXIT_SUCCESS;
    return 0;
}