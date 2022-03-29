#ifndef PGMimageProcessor_H
#define PGMimageProcessor_H
#include "ConnectedComponent.h"
#include <string>
#include <vector>

namespace yrlnic001
{
    class PGMimageProcessor
    {
    private:
        int minCoponentSize, maxComponentSize;
        unsigned char *image;                         // holds the unsigned chars that make up the .pgm image
        int width, height;                            // width and height of image
        std::vector<ConnectedComponent *> components; // container of pointers to component objects

    public:
        PGMimageProcessor(int min, int max);                        // constructor
        ~PGMimageProcessor();                                       // destructor
        PGMimageProcessor(const PGMimageProcessor &p);              // Copy Constructor
        PGMimageProcessor(PGMimageProcessor &&p);                   // Move constructor
        PGMimageProcessor &operator=(const PGMimageProcessor &rhs); // Copy Assignment Operator
        PGMimageProcessor &operator=(PGMimageProcessor &&rhs);      // Move Assignment Operator

        void readInFile(std::string filename);
        void testOutput();
        int extractComponents(int threshold, int minValidSize); // mkae thresh unsigned char
        int filterComponentsBySize(int minSize, int maxSize);
        bool writeComponents(const std::string &outFileName);
        int getComponentCount(void) const;
        int getLargestSize(void) const;
        int getSmallestSize(void) const;
    };
}

#endif
