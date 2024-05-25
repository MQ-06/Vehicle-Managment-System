#ifndef CAR_H
#define CAR_H
#include "car.h"

Car::Car() : VEHICLE(), numDoor(0) {}
Car::Car(string m, string model, int years, double price, int doors) : VEHICLE(m, model, years, price)
{
    setNumDoor(doors);
}
void Car::setNumDoor(int door)
{

    this->numDoor = door;
}
int Car::getDoor() const { return numDoor; }
void Car::display_info() const
{
    cout << "CAR DETAILS: " << endl;
    cout << " Make: " << make << '\n'
         << " Model: " << model << '\n'
         << " Year: " << year << '\n'
         << " Price: " << price << " rupees" << '\n'
         << " Number of Doors: " << numDoor << endl;
}

#endif