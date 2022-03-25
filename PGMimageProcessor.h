#ifndef PGMimageProcessor_H
#define PGMimageProcessor_H

#include <string>

namespace yrlnic001
{
    class PGMimageProcessor
    {
        std::string filename;
        int minCoponentSize, maxComponentSize;
        int threshold;

    public:
        PGMimageProcessor(std::string, int min, int max, int thresh); // constructor
        ~PGMimageProcessor();                                         // destructor
        PGMimageProcessor(const PGMimageProcessor &p);                // Copy Constructor
        PGMimageProcessor(PGMimageProcessor &&p);                     // Move constructor
        PGMimageProcessor &operator=(const PGMimageProcessor &rhs);   // Copy Assignment Operator
        PGMimageProcessor &operator=(PGMimageProcessor &&rhs);        // Move Assignment Operator

        void readInFile(std::string filename);
    };
}

#endif
