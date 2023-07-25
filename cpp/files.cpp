#include <iostream>
#include <fstream>
#include <string>

void write_to_file(std::string file_name)
{
    // Create and open a text file
    std::ofstream myFile(file_name);

    // Write to the file
    myFile << "This is a new file!\n";
    myFile << "The file name is sample.txt.\n";
    myFile << "I hope this was an interesting read!\n";

    // Close the file
    myFile.close();
}

void read_file(std::string file_name)
{
    // Create a text string, which is used to output the text file
    std::string myText;

    // Read from the text file
    std::ifstream myFile(file_name);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(myFile, myText)) {
        // Output the text from the file
        std::cout << myText << std::endl;
    }

    // Close the file
    myFile.close();
}

int main(void)
{
    std::string file_name = "cpp/sample.txt";
    write_to_file(file_name);
    read_file(file_name);

    return 0;
}