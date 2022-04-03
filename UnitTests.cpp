#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <string>
#include <sstream>
#include <memory>
#include "PGMimageProcessor.h"
#include "ConnectedComponent.h"

using namespace std;

#define CONST // const

TEST_CASE("Connected Components", "[ConnectedComponents]")
{
    yrlnic001::ConnectedComponent c(0);
    std::pair<int, int> p1;
    p1.first = 0;
    p1.second = 0;
    c.addPixel(p1);
    c.addPixel(p1);
    c.addPixel(p1);
    c.addPixel(p1);
    SECTION("Num pixels")
    {
        REQUIRE(c.getNumPixels() == 4);
    }
    SECTION("IDs")
    {
        REQUIRE(c.getID() == 1);
    }
}

TEST_CASE("Componets vector", "[Components]")
{
    yrlnic001::PGMimageProcessor p(1, 5);
    std::pair<int, int> p1;
    p1.first = 0;
    p1.second = 0;

    std::shared_ptr<yrlnic001::ConnectedComponent> s = std::make_shared<yrlnic001::ConnectedComponent>(0);

    s->addPixel(p1);
    s->addPixel(p1);
    s->addPixel(p1);
    s->addPixel(p1);
    p.addComponent(s);

    std::shared_ptr<yrlnic001::ConnectedComponent> b = std::make_shared<yrlnic001::ConnectedComponent>(0);

    b->addPixel(p1);
    b->addPixel(p1);
    b->addPixel(p1);
    b->addPixel(p1);
    p.addComponent(b);

    std::shared_ptr<yrlnic001::ConnectedComponent> c = std::make_shared<yrlnic001::ConnectedComponent>(0);

    p.addComponent(c);

    std::shared_ptr<yrlnic001::ConnectedComponent> d = std::make_shared<yrlnic001::ConnectedComponent>(0);

    d->addPixel(p1);
    d->addPixel(p1);
    d->addPixel(p1);
    d->addPixel(p1);
    d->addPixel(p1);
    d->addPixel(p1);
    d->addPixel(p1);
    d->addPixel(p1);
    p.addComponent(d);

    SECTION("Component count")
    {
        REQUIRE(p.getComponentCount() == 4);
    }
    SECTION("Filter Component by size")
    {
        REQUIRE(p.filterComponentsBySize(1, 5) == 2);
    }
    SECTION("Largest Component")
    {
        REQUIRE(p.getLargestSize() == 8);
    }
    SECTION("Largest Component")
    {
        REQUIRE(p.getSmallestSize() == 0);
    }
    SECTION("Print Data")
    {
        p.printComponentData(*s);
    }
}
