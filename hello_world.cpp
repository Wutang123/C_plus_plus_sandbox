#include <iostream>
#include <string>

int main(void) 
{
    // Printing
    std::cout << "Hello World!\n";
    std::cout << "This is my first C++ program.\n";
    std::cout << "\n";

    // Input
    // int x;
    // std::cout << "Input value: ";
    // std::cin >> x;
    // std::cout << "Value inputted is: " << x << std::endl;
    // std::cout << "\n";

    // std::string myFullName = "HELP";
    // std::cout << "Input your full name: ";
    // getline(std::cin, myFullName); // Use getline() to read in entire string. std::cin will not get " " characters
    // std::cout << "Your full name is: " << myFullName << std::endl;
    // std::cout << "\n";

    // Structs
    struct Profile {
        int age;
        std::string name;
    };

    Profile user1;
    user1.age = 10;
    user1.name = "Wutang";
    std::cout << user1.age << std::endl;
    std::cout << user1.name << std::endl;
    std::cout << "\n";

    // References and Pointers
    std::string original = "Hello";
    std::string &reference_original = original;
    std::string* ptr_original = &original;
    std::string backup = original;

    reference_original = "World"; 
    *ptr_original      = "Welcome"; 
    // backup             = "Earth"; 

    std::cout << "original:           " << original           << ", memory address: " << &original << std::endl;
    std::cout << "reference_original: " << reference_original << ", memory address: " << &reference_original << std::endl;
    std::cout << "ptr_original:       " << ptr_original       << ", memory address: " << &ptr_original << ", dereferenced: " << *ptr_original << std::endl;
    std::cout << "backup:             " << backup             << ", memory address: " << &backup << std::endl;

    std::cout << "\n";

    return 0;
}