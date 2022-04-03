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
    bool p = false;
    bool w = false;
    std::string outfile;
    while (argc != 0) // loop until all flags are processed
    {
        std::string flag = argv[counter]; // gets the flag

        if (flag == "-s")
        {
            min = std::stoi(argv[counter + 1]); // min valid component size
            max = std::stoi(argv[counter + 2]); // max valid component size
            counter += 3;
            argc -= 3;
            // std::cout << "flag s " << min << ":" << max << std::endl;
        }
        if (flag == "-t")
        {
            thresh = std::stoi(argv[counter + 1]); // threshold for counter detection
            counter += 2;
            argc -= 2;
            // std::cout << "flag t " << thresh << std::endl;
        }

        if (flag == "-p")
        { // print out component data ,total component number and sizes of smalles and largest componets
            counter += 1;
            argc -= 1;
            p = true;
            // std::cout << "flag p " << std::endl;
        }
        if (flag == "-w")
        { // write out retained components to PGM file

            outfile = argv[counter + 1];
            counter += 2;
            argc -= 2;
            w = true;
            // std::cout << "flag w " << outfile << std::endl;
        }
    }

    yrlnic001::PGMimageProcessor myObj(min, max); // creates object of PGMimageProcessor class
    myObj.readInFile(filename);                   // reads in file
    myObj.TestImage(thresh);
    myObj.testOutput("A");
    myObj.extractComponents(thresh, min);
    // myObj.writeComponents("stuff.pgm");
    myObj.testOutput("B");
    // myObj.~PGMimageProcessor();

    if (p)
    {
        std::vector<std::shared_ptr<yrlnic001::ConnectedComponent>> c = myObj.getComponents();

        for (auto it = c.begin(); it < c.end(); it++)
        {
            myObj.printComponentData(**it);
        }
        std::cout << "The total number of components are: " << myObj.getComponentCount() << std::endl;
        std::cout << "The largest component has size: " << myObj.getLargestSize() << std::endl;
        std::cout << "The smallest component has size: " << myObj.getSmallestSize() << std::endl;
    }
    if (w)
    {
        myObj.writeComponents(outfile);
    }
    return 0;
}