#include "PGMimageProcessor.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

yrlnic001::PGMimageProcessor::PGMimageProcessor(int min, int max) : minCoponentSize(min), maxComponentSize(max)
{ // constructor
}

yrlnic001::PGMimageProcessor::~PGMimageProcessor()
{ // destructor

    delete[] image;
}

yrlnic001::PGMimageProcessor::PGMimageProcessor(const yrlnic001::PGMimageProcessor &p)
{ // Copy Constructor
}

yrlnic001::PGMimageProcessor::PGMimageProcessor(yrlnic001::PGMimageProcessor &&p)
{ // move constructor
  // set pointer to null
}

yrlnic001::PGMimageProcessor &yrlnic001::PGMimageProcessor::operator=(const yrlnic001::PGMimageProcessor &rhs)
{
    if (this != &rhs) // Checks to make that we are not performing a self-assignment
    {
    }
    return *this;
}

yrlnic001::PGMimageProcessor &yrlnic001::PGMimageProcessor::operator=(yrlnic001::PGMimageProcessor &&rhs)
{                     // Move Assignment Operator
    if (this != &rhs) // Checks to make that we are not performing a
    // self-assignment
    {
    }
    return *this;
}

void yrlnic001::PGMimageProcessor::readInFile(std::string filename)
{
    std::ifstream myFile;

    myFile.open(filename, std::ios::binary); // reads the file in as binary
    std::string line;
    getline(myFile, line); // p5 always first in the file
    getline(myFile, line);
    while (line[0] == '#') // gets rid of comment lines
    {
        getline(myFile, line);
    }

    std::istringstream iss(line); // reads number of pixel rows and columns
    int rows, columns;
    iss >> columns;
    iss >> rows;

    width = columns;
    height = rows;

    std::string temp;
    myFile >> temp >> std::ws;
    // pointer to the array that holds the image
    int size = rows * columns;
    image = new unsigned char[size]; // dynamically allocates memory to image array

    myFile.read((char *)image, size); // read clock of unsgned chars in
    if (!myFile)
    {
        std::cout << "false" << std::endl;
    }

    if (myFile)
        std::cout << "all characters read successfully." << std::endl;
    myFile.close();
}

void yrlnic001::PGMimageProcessor::testOutput()
{
    // here because processFrames doesnt work
    std::ofstream outfile("test.pgm", std::ofstream::binary);
    outfile << "P5\n"
            << width << " " << height << "\n"
            << "255"
            << "\n";
    int size = width * height;
    outfile.write((char *)image, size);
    outfile.close();
}

int yrlnic001::PGMimageProcessor::extractComponents(int threshold, int minValidSize)
{
    /* process the input image to extract all the connected components,
 based on the supplied threshold (0...255) and excluding any components
 of less than the minValidSize. The final number of components that
 you store in your container (after discarding undersized one)
 must be returned.
 */
}

int filterComponentsBySize(int minSize, int maxSize)
{
    /* iterate - with an iterator - though your container of connected
components and filter out (remove) all the components which do not
obey the size criteria pass as arguments. The number remaining
after this operation should be returned.
*/
}

bool writeComponents(const std::string &outFileName)
{
    /* create a new PGM file which contains all current components
(255=component pixel, 0 otherwise) and write this to outFileName as a
valid PGM. the return value indicates success of operation
*/
}

/*
int getComponentCount(void) const
{
    // return number of components
}

int getLargestSize(void) const
{
    // return number of pixels in largest components
}

int getSmallestSize(void) const
{
    // return number of pixels in smallest component
}
*/