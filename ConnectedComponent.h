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
        int numPixels, componentID;
        std::vector<std::pair<int, int>> coords; // holds the coordinates of each pixel in the component

    public:
        ConnectedComponent(int oldID); // finish this
        void addPixel(std::pair<int, int> p);
        int getNumPixels();
        int getID();
        // implement big 6
    };
}

#endif
