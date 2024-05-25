#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;

// Base Class
class VEHICLE
{
protected:
    string make;
    string model;
    int year;
    double price;

public:
    VEHICLE();
    VEHICLE(string m, string model, int year, double price);
    void setMake(string m);
    void setModel(string model);
    void setYear(int year);
    void setPrice(double price);
    string getModel() const;
    string getMake() const;
    int getYear() const;
    double getPrice() const;
    virtual ~VEHICLE();

    virtual void display_info() const=0;
};