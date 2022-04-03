#include <string>
#include <iostream>
#include "PGMimageProcessor.h"
void processFlag()
{
}
int main(int argc, char *argv[])
{
    int min, max, thresh;
    // unsigned char thresh;
    std::string filename;
    // validate input
    if (argc == 1)
    {
        std::cout << "Error: Please run again with parameters" << std::endl;
        std::exit(0);
    }

    int len = std::string(argv[argc - 1]).length(); // length of the final parameter given (filename)

    if (std::string(argv[argc - 1]).substr(len - 4) != ".pgm") // checks for correct file extension
    {
        std::cout << "Error: Incorrect file format" << std::endl;
        std::exit(0);
    }
    else
    {
        filename = argv[argc - 1];
    }

    // to-do
    // handle input where incorrect number of parameters given for tag

    argc -= 2; // remove counter for filename and executable. The rest are flags
    int counter = 1;
    while (argc != 0) // loop until all flags are processed
    {
        std::string flag = argv[counter]; // gets the flag

        if (flag == "-s")
        {
            min = std::stoi(argv[counter + 1]); // min valid component size
            max = std::stoi(argv[counter + 2]); // max valid component size
            counter += 3;
            argc -= 3;
            std::cout << "flag s " << min << ":" << max << std::endl;
        }
        if (flag == "-t")
        {
            thresh = std::stoi(argv[counter + 1]); // threshold for counter detection
            counter += 2;
            argc -= 2;
            std::cout << "flag t " << thresh << std::endl;
        }

        if (flag == "-p")
        { // print out component data ,total component number and sizes of smalles and largest componets
            counter += 1;
            argc -= 1;
            std::cout << "flag p " << std::endl;
        }
        if (flag == "-w")
        { // write out retained components to PGM file

            std::string outfile = argv[counter + 1];
            counter += 2;
            argc -= 2;
            std::cout << "flag w " << outfile << std::endl;
        }
    }

    yrlnic001::PGMimageProcessor myObj(min, max); // creates object of PGMimageProcessor class
    myObj.readInFile(filename);                   // reads in file
    myObj.TestImage(thresh);
    myObj.extractComponents(thresh, min);
    std::cout << "components extracted" << std::endl;
    std::cout << "number of components are: " << myObj.components.size() << std::endl;
    // myObj.writeComponents("stuff.pgm");
    //  myObj.testOutput();
    // myObj.~PGMimageProcessor();
    return 0;
}