#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "motorcycle.h"

MotorCycle::MotorCycle() : VEHICLE(), engineSize(0) {}
MotorCycle::MotorCycle(string m, string model, int years, double price, double engine_size) : VEHICLE(m, model, years, price)
{
    setEngineSize(engine_size);
}
void MotorCycle::setEngineSize(double size)
{
    if (size > 0.0)
        this->engineSize = size;
    else
        throw invalid_argument("INVALID ENGINE SIZE");
}
double MotorCycle::getEngineSize() const { return engineSize; }
void MotorCycle::display_info() const
{
    cout << "BIKE DETAILS:  " << endl;
    cout << " Make: " << make << '\n'
         << " Model: " << model << '\n'
         << " Year: " << year << '\n'
         << " Price: " << price << " rupees" << '\n'
         << " Engine Size: " << engineSize << "cc" << endl;
}

#endif