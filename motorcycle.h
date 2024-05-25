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

class MotorCycle : public VEHICLE
{
private:
    double engineSize;

public:
    MotorCycle();
    MotorCycle(string m, string model, int years, double price, double engine_size);
    void setEngineSize(double size);
    double getEngineSize() const;
    void display_info() const override;
};