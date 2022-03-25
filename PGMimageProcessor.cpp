#include "PGMimageProcessor.h"
#include <iostream>
#include <string>
#include <fstream>
#include <istream>

/*
yrlnic001::PGMimageProcessor::PGMimageProcessor(std::string f, int min, int max, int thresh) : filename(f), minCoponentSize(min), maxComponentSize(max), threshold(thresh)
{ // constructor
}
yrlnic001::PGMimageProcessor::~PGMimageProcessor()
{ // destructor
}

*/

yrlnic001::PGMimageProcessor::PGMimageProcessor(const yrlnic001::PGMimageProcessor &p) : filename(p.filename)
{ // Copy Constructor
    /*
    id is a char pointer
    if (p.id != nullptr)
    {
        id = new char(*p.id);
    }
    */
}

yrlnic001::PGMimageProcessor::PGMimageProcessor(yrlnic001::PGMimageProcessor &&p) : filename(p.filename)
{ // move constructor
  // set pointer to null
}

yrlnic001::PGMimageProcessor &yrlnic001::PGMimageProcessor::operator=(const yrlnic001::PGMimageProcessor &rhs)
{
    if (this != &rhs) // Checks to make that we are not performing a self-assignment
    {
        this->filename = rhs.filename;
        // this->col = rhs.col;

        // for pointer
        /*
        if (this->id != nullptr)
        {
            delete this->id; // 'this' may already be managing a bit of
            // memory so we must release it to prevent any memory leaks.
            this->id = nullptr;
        }
        if (rhs.id != nullptr)
        {
            this->id = new char(*rhs.id);
        }
        */
    }
    return *this;
}

yrlnic001::PGMimageProcessor &yrlnic001::PGMimageProcessor::operator=(yrlnic001::PGMimageProcessor &&rhs)
{                     // Move Assignment Operator
    if (this != &rhs) // Checks to make that we are not performing a
    // self-assignment
    {
        this->filename = rhs.filename;
        // this->col = rhs.col;

        // for pointer
        /*
        if (this->id != nullptr)
        {
            delete this->id; // 'this' may already be managing a bit
            // of memory so we must release it to prevent any memory leaks.
            this->id = nullptr;
        }
        if (rhs.id != nullptr)
        {
            this->id = rhs.id;
            rhs.id = nullptr; // rhs is no longer responsible for the bit
            // of memory 'rhs.id' points to so we set it to nullptr
        }
        */
    }
    return *this;
}

void yrlnic001::PGMimageProcessor::readInFile(std::string filename)
{
    /*
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

    std::string temp;
    myFile >> temp >> std::ws;
    // pointer to the array that holds the image
    int size = rows * columns;
    image = new unsigned char[size]; // dynamically allocates memory to image array

    myFile.read((char *)image, size); // read clock of unsgned chars in
    if (myFile)
        std::cout << "all characters read successfully." << std::endl;
    myFile.close();
    */
}
