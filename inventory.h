#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include "car.cpp"
#include "truck.cpp"
#include "motorcycle.cpp"
// #include "VEHCILE.cpp"
using namespace std;

class INVENTORY
{
private:
    VEHICLE **vehicles;
    int countVehicles;

public:
    INVENTORY();
    ~INVENTORY();
    void addCar(VEHICLE *c);
    void addTruck(VEHICLE *t);
    void addBike(VEHICLE *m);
    void removeCar(string &model);
    void removeTruck(string &model);
    void removeBike(string &model);
    void searchCar();
    void searchTruck();
    void searchBike();
    void sortCar();
    void sortTruck();
    void sortBike();
    void display_cars();
    void display_trucks();
    void display_bikes();
    void display_all_inventory();
};