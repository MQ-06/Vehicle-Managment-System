#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include "VEHICLE.cpp"
using namespace std;
// Derived Class

class Car : public VEHICLE
{
private:
    int numDoor;

public:
    Car();
    Car(string m, string model, int years, double price, int doors);
    void setNumDoor(int door);
    int getDoor() const;
    void display_info() const override;
};