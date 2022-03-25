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
        ConnectedComponent(int numPixels); // finish this
        // implement big 6
    };
}

#endif
