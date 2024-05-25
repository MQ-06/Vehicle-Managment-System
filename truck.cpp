#ifndef TRUCK_H
#define TRUCK_H
#include "truck.h"
Truck::Truck() : VEHICLE(), bedSize("") {}
Truck::Truck(string m, string model, int years, double price, string bedSize) : VEHICLE(m, model, years, price)
{
    setBedSize(bedSize);
}
void Truck::setBedSize(string size)
{
    if (!size.empty())
        this->bedSize = size;
    else
    {
        throw invalid_argument("INVALID BED SIZE");
    }
}
string Truck::getBedSize() const { return bedSize; }
void Truck::display_info() const
{
    cout << "TRUCK DETAILS: " << endl;
    cout << " Make: " << make << '\n'
         << " Model: " << model << '\n'
         << " Year: " << year << '\n'
         << " Price: " << price << " rupees" << '\n'
         << " Bed Size: " << bedSize << endl;
}

#endif