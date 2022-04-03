#include "PGMimageProcessor.h"
#include "ConnectedComponent.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <memory>

yrlnic001::PGMimageProcessor::PGMimageProcessor(int min, int max) : minCoponentSize(min), maxComponentSize(max)
{ // constructor
}

yrlnic001::PGMimageProcessor::~PGMimageProcessor()
{ // destructor

    delete[] image;
}

yrlnic001::PGMimageProcessor::PGMimageProcessor(const yrlnic001::PGMimageProcessor &p)
{ // Copy Constructor
}

yrlnic001::PGMimageProcessor::PGMimageProcessor(yrlnic001::PGMimageProcessor &&p)
{ // move constructor
  // set pointer to null
}

yrlnic001::PGMimageProcessor &yrlnic001::PGMimageProcessor::operator=(const yrlnic001::PGMimageProcessor &rhs)
{
    if (this != &rhs) // Checks to make that we are not performing a self-assignment
    {
    }
    return *this;
}

yrlnic001::PGMimageProcessor &yrlnic001::PGMimageProcessor::operator=(yrlnic001::PGMimageProcessor &&rhs)
{                     // Move Assignment Operator
    if (this != &rhs) // Checks to make that we are not performing a
    // self-assignment
    {
    }
    return *this;
}

void yrlnic001::PGMimageProcessor::readInFile(std::string filename)
{
    std::ifstream myFile;

    myFile.open(filename, std::ios::binary); // reads the file in as binary
    std::string line;
    getline(myFile, line); // p5 always first in the file
    getline(myFile, line);
    while (line[0] == '#') // gets rid of comment lines
    {
        getline(myFile, line);
    }

    std::istringstream iss(line); // reads number of pixel rows and columns
    int rows, columns;
    iss >> columns;
    iss >> rows;

    width = columns;
    height = rows;

    std::string temp;
    myFile >> temp >> std::ws;
    // pointer to the array that holds the image
    int size = rows * columns;

    image = new unsigned char[size]; // dynamically allocates memory to image array

    myFile.read((char *)image, size); // read clock of unsgned chars in

    if (myFile)
        std::cout << "all characters read successfully." << std::endl;
    myFile.close();
}

void yrlnic001::PGMimageProcessor::testOutput(std::string n)
{
    // here because processFrames doesnt work
    std::ofstream outfile(n + "test.pgm", std::ofstream::binary);
    outfile << "P5\n"
            << width << " " << height << "\n"
            << "255"
            << "\n";
    int size = width * height;
    outfile.write((char *)image, size);
    outfile.close();
}

int yrlnic001::PGMimageProcessor::extractComponents(int threshold, int minValidSize)
{
    int size = width * height;

    int counter = 0;
    // std::cout << "threshold is: " << threshold << std::endl;
    // std::cout << "size is : " << size << std::endl;
    for (int i = 0; i < size; ++i) // loop from top left along each row
    {
        if (image[i] >= threshold)
        {
            ++counter;
            // std::cout << "i number: " << i << std::endl;
            //  std::unique_ptr<ConnectedComponent> compPtr = std::make_unique<ConnectedComponent>(components[-1]->getID()); // smart pointer to component object
            int id = 0;

            if (components.size() != 0)
                id = components.back()->getID();

            std::shared_ptr<ConnectedComponent> comp = std::make_shared<ConnectedComponent>(id); // makes a unique ptr to them ConnectedComponent object.
            std::queue<int> q;
            q.push(i); // adds the address of the first pixel in this component
            beginComponentSearch(q, threshold, comp);

            if (comp->getNumPixels() >= minValidSize)
                components.push_back(comp);
            std::cout << "component size: " << comp->getNumPixels() << std::endl;
            // std::cout << "this should be 0 it is: " << image[i] << std::endl;
        }
    }

    return components.size();
}

void yrlnic001::PGMimageProcessor::beginComponentSearch(std::queue<int> q, int thresh, std::shared_ptr<ConnectedComponent> co)
{
    std::shared_ptr<ConnectedComponent> comp = co;
    int size = width * height;
    while (!q.empty())
    {
        int num = q.front();

        std::pair<int, int> p1;
        p1.first = num % width;
        p1.second = num % height;
        comp->addPixel(p1);
        // std::cout << "pixel num: " << num << std::endl;
        q.pop();
        testImage.push_back(num);
        image[num] = 0; // so we wont visit this pixel again.

        // find pixels boardering this one;
        int n, s, e, w;
        n = num - width;
        e = num + 1;
        s = num + width;
        w = num - 1;

        // if the neighbouring pixel is greater than threshold and within the image we add it to the queue
        if (image[n] >= thresh && checkValue(n, size)) // is pixel to the north is in the foreground
        {
            image[n] = 0;
            q.push(n);
        }
        if (image[e] >= thresh && checkValue(e, size)) // is pixel to the east is in the foreground
        {
            image[e] = 0;
            q.push(e);
        }
        if (image[s] >= thresh && checkValue(s, size)) // is pixel to the south is in the foreground
        {
            image[s] = 0;
            q.push(s);
        }
        if (image[w] >= thresh && checkValue(w, size)) // is pixel to the west is in the foreground
        {
            image[w] = 0;
            q.push(w);
        }
    }
}

bool yrlnic001::PGMimageProcessor::checkValue(int i, int size)
{
    // if wihtin the image returns true;
    if (i < 0 || i >= size)
    {
        return false;
    }
    return true;
}

void yrlnic001::PGMimageProcessor::TestImage(int thresh)
{
    int size = width * height;
    int counter = 0;
    int otherCounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (image[i] > thresh)
        {
            image[i] = 255;
            // std::cout << image[i] << std::endl;
            ++counter;
        }
        else
        {
            image[i] = 0;
            ++otherCounter;
        }
    }
    // std::cout << "counter:" << counter << std::endl;
    // std::cout << "other counter:" << otherCounter << std::endl;
}

int yrlnic001::PGMimageProcessor::filterComponentsBySize(int minSize, int maxSize)
{

    int counter = 0;
    std::shared_ptr<ConnectedComponent> s;
    for (auto it = components.begin(); it != components.end(); ++it)
    {
        // if the componet within the bounds
        s = *it;
        if (s->getNumPixels() > minSize && s->getNumPixels() < maxSize)
        {
            ++counter;
        }
    }
    return counter;
}

bool yrlnic001::PGMimageProcessor::writeComponents(const std::string &outFileName)
{
    std::string name = outFileName;
    std::cout << name << std::endl;

    std::ofstream outfile(name, std::ofstream::binary);
    outfile << "P5\n"
            << width << " " << height << "\n"
            << "255"
            << "\n";
    int size = width * height;
    outfile.write((char *)image, size);
    outfile.close();
    return false;
}

int yrlnic001::PGMimageProcessor::getComponentCount(void) const
{
    return components.size();
}

int yrlnic001::PGMimageProcessor::getLargestSize(void) const
{
    int max = 0;
    std::shared_ptr<ConnectedComponent> s;
    for (auto it = begin(components); it != end(components); ++it)
    {
        s = *it;
        // if the componet within the bounds
        if (s->getNumPixels() > max)
        {
            max = s->getNumPixels();
        }
    }

    return max;
}

int yrlnic001::PGMimageProcessor::getSmallestSize(void) const
{
    std::shared_ptr<ConnectedComponent> s;
    int min = 0;
    for (auto it = begin(components); it != end(components); ++it)
    {
        // if the componet within the bounds
        s = *it;
        if (s->getNumPixels() < min)
        {
            min = s->getNumPixels();
        }
    }
    return min;
}

void yrlnic001::PGMimageProcessor::printComponentData(const ConnectedComponent &theComponent) const
{
    ConnectedComponent c(theComponent);
    std::cout << "ID: " << c.getID() << " Number of Pixels: " << c.getNumPixels() << std::endl;
}

// testing

void yrlnic001::PGMimageProcessor::addComponent(std::shared_ptr<ConnectedComponent> s)
{
    components.push_back(s);
}