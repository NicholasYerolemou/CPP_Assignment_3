#ifndef ConnectedComponent_H
#define ConnectedComponent_H

#include "PGMimageProcessor.h"
#include <utility>
#include <vector>

namespace yrlnic001
{
    class ConnectedComponent
    {
    private:
        int numPixels = 0;
        int componentID = 0;
        std::vector<std::pair<int, int>> coords; // holds the coordinates of each pixel in the component

    public:
        ConnectedComponent(int oldID);
        ~ConnectedComponent();                                        // finish this                                    // destructor
        ConnectedComponent(const ConnectedComponent &p);              // Copy Constructor
        ConnectedComponent(ConnectedComponent &&p);                   // Move constructor
        ConnectedComponent &operator=(const ConnectedComponent &rhs); // Copy Assignment Operator
        ConnectedComponent &operator=(ConnectedComponent &&rhs);      // Move Assignment Operator
        void addPixel(std::pair<int, int> p);
        int getNumPixels();
        int getID();
        // implement big 6
    };
}

#endif
