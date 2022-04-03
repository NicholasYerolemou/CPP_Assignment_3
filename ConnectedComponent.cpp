#include "ConnectedComponent.h"

yrlnic001::ConnectedComponent::ConnectedComponent(int oldID)
{
    componentID = oldID + 1;
}

yrlnic001::ConnectedComponent::~ConnectedComponent()
{ // destructor
}

yrlnic001::ConnectedComponent::ConnectedComponent(const yrlnic001::ConnectedComponent &p) : componentID(p.componentID), numPixels(p.numPixels), coords(p.coords)
{ // Copy Constructor
}

yrlnic001::ConnectedComponent::ConnectedComponent(yrlnic001::ConnectedComponent &&p) : componentID(p.componentID), numPixels(p.numPixels), coords(p.coords)
{ // move constructor
}

yrlnic001::ConnectedComponent &yrlnic001::ConnectedComponent::operator=(const yrlnic001::ConnectedComponent &rhs)
{
    if (this != &rhs) // Checks to make that we are not performing a self-assignment
    {
        componentID = rhs.componentID;
        numPixels = rhs.numPixels;
        coords = rhs.coords;
    }
    return *this;
}

yrlnic001::ConnectedComponent &yrlnic001::ConnectedComponent::operator=(yrlnic001::ConnectedComponent &&rhs)
{                     // Move Assignment Operator
    if (this != &rhs) // Checks to make that we are not performing a
    // self-assignment
    {
        componentID = rhs.componentID;
        numPixels = rhs.numPixels;
        coords = rhs.coords;
    }
    return *this;
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
