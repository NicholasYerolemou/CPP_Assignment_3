#ifndef PGMimageProcessor_H
#define PGMimageProcessor_H
#include "ConnectedComponent.h"
#include <string>
#include <vector>
#include <queue>
#include <memory>

namespace yrlnic001
{
    class PGMimageProcessor
    {
    private:
        int minCoponentSize, maxComponentSize;
        unsigned char *image; // holds the unsigned chars that make up the .pgm image
        std::vector<int> testImage;
        int width, height;                                           // width and height of image
        std::vector<std::shared_ptr<ConnectedComponent>> components; // container of smart pointers to component objects

    public:
        PGMimageProcessor(int min, int max);                        // constructor
        ~PGMimageProcessor();                                       // destructor
        PGMimageProcessor(const PGMimageProcessor &p);              // Copy Constructor
        PGMimageProcessor(PGMimageProcessor &&p);                   // Move constructor
        PGMimageProcessor &operator=(const PGMimageProcessor &rhs); // Copy Assignment Operator
        PGMimageProcessor &operator=(PGMimageProcessor &&rhs);      // Move Assignment Operator

        void readInFile(std::string filename);
        void testOutput(std::string n);
        int extractComponents(int threshold, int minValidSize); // mkae thresh unsigned char
        int filterComponentsBySize(int minSize, int maxSize);
        bool writeComponents(const std::string &outFileName);
        int getComponentCount(void) const;
        int getLargestSize(void) const;
        int getSmallestSize(void) const;
        void printComponentData(const ConnectedComponent &theComponent) const;
        void beginComponentSearch(std::queue<int> q, int thresh, std::shared_ptr<ConnectedComponent> comp);
        bool checkValue(int i, int size);
        void TestImage(int thresh);
        int getNumComponents();
        std::vector<std::shared_ptr<ConnectedComponent>> getComponents();
        std::vector<int> getForeground();

        // testing
        void addComponent(std::shared_ptr<ConnectedComponent> s);
    };
}

#endif
