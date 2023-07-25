#include <iostream>

int main(void)
{
    try
    {
        int myNumber = 18;
        if (myNumber >= 21)
        {
            std::cout << "ACCESS GRANTED, myNumber=" << myNumber << " is greater than or equal to 21" << std::endl;
        }
        else
        {
            throw 400;
        }
    }
    catch(int errorCode)
    {
        std::cerr << "ACCESS DENIED: errorCode=" << errorCode << std::endl;
    }
    
    return 0;
}