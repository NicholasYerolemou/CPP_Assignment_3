#include "PGMimageProcessor.h"
#include <iostream>
#include <string>

yrlnic001::PGMimageProcessor::PGMimageProcessor(std::string f, int min, int max) : filename(f), minCoponentSize(min), maxComponentSize(max)
{ // constructor
}
yrlnic001::PGMimageProcessor::~PGMimageProcessor()
{ // destructor
}

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

int main(int argc, char *argv[])
{
    // validate input
    if (std::string(argv[1]).substr(-3) != ".pgm") // checks for correct type of file
    {
        std::cout << "Error: Incorrect file format";
        std::exit(0);
    }
    // do more error checking
    yrlnic001::PGMimageProcessor obj(argv[-1], std::stoi(argv[2]), std::stoi(argv[3])); // calls constructor

    obj.readInFile();
    return 0;
}