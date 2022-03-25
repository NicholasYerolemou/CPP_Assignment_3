#ifndef PGMimageProcessor_H
#define PGMimageProcessor_H

#include <string>
#include <vector>

namespace yrlnic001
{
    class PGMimageProcessor
    {
        int minCoponentSize, maxComponentSize;
        int threshold;
        unsigned char *image; // holds the unsigned chars that make up the .pgm image
        int width, height;    // width and height of image

    public:
        PGMimageProcessor(int min, int max, int thresh);            // constructor
        ~PGMimageProcessor();                                       // destructor
        PGMimageProcessor(const PGMimageProcessor &p);              // Copy Constructor
        PGMimageProcessor(PGMimageProcessor &&p);                   // Move constructor
        PGMimageProcessor &operator=(const PGMimageProcessor &rhs); // Copy Assignment Operator
        PGMimageProcessor &operator=(PGMimageProcessor &&rhs);      // Move Assignment Operator

        void readInFile(std::string filename);
        void testOutput();
    };
}

#endif
