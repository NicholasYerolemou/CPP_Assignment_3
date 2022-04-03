#include "ConnectedComponent.h"

yrlnic001::ConnectedComponent::ConnectedComponent(int oldID)
{
    componentID = oldID + 1;
}

void yrlnic001::ConnectedComponent::addPixel(std::pair<int, int> p)
{
    coords.push_back(p);
    ++numPixels; // a new pixel is added, increase count of pixels
}

int yrlnic001::ConnectedComponent::getNumPixels()
{
    return coords.size();
}

int yrlnic001::ConnectedComponent::getID()
{
    return componentID;
}