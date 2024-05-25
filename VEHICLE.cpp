#ifndef VEHICLE_H
#define VEHICLE_H
#include "VEHICLE.h"

VEHICLE::VEHICLE() : make(" "), model(" "), year(0), price(0.0) {}
 VEHICLE::~VEHICLE() {}

VEHICLE::VEHICLE(string m, string model, int year, double price)
{
    setMake(m);
    setModel(model);
    setYear(year);
    setPrice(price);
}
void VEHICLE::setMake(string m)
{
    if (!m.empty())
        this->make = m;
    else
    {
        throw invalid_argument("INVALID MAKE");
    }
}

void VEHICLE::setModel(string model)
{

    if (!model.empty())
        this->model = model;
    else
    {
        throw invalid_argument("INVALID MODEL");
    }
}
void VEHICLE::setYear(int year)
{

    if (year > 0)
        this->year = year;
    else
    {
        throw invalid_argument("INVALID YEAR");
    }
}
void VEHICLE::setPrice(double price)
{

    if (price > 0)
        this->price = price;
    else
    {
        throw invalid_argument("INVALID PRICE");
    }
}
string VEHICLE::getModel() const { return model; }
string VEHICLE::getMake() const { return make; }
int VEHICLE::getYear() const { return year; }
double VEHICLE::getPrice() const { return price; }

#endif
