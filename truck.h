#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include "VEHICLE.cpp"

// Derived Class
class Truck : public VEHICLE
{
    string bedSize;

public:
    Truck();
    Truck(string m, string model, int years, double price, string bedSize);
    void setBedSize(string size);
    string getBedSize() const;
    void display_info() const override;
};