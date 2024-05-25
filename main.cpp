#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include "VEHICLE.cpp"
#include "car.cpp"
#include "truck.cpp"
#include "motorcycle.cpp"
#include "inventory.cpp"
using namespace std;
void menu()
{

    cout << "MENU:" << endl;
    cout << "1. Add a Car " << '\n'
         << "2. Add a Truck " << '\n'
         << "3. Add a Motorcycle" << '\n'
         << "4. Remove a Car" << '\n'
         << "5. Remove a Truck" << '\n'
         << "6. Remove a Motorcycle" << '\n'
         << "7. Search a Car" << '\n'
         << "8. Search a Truck " << '\n'
         << "9. Search a Motorcycle" << '\n'
         << "10. Sort Cars" << '\n'
         << "11. Sort Trucks" << '\n'
         << "12. Sort Motorcycles" << endl;
    cout << "13. Display Cars " << endl;
    cout << "14. Display Trucks " << endl;
    cout << "15. Display Bikes " << endl;
    cout << "16. Display all inventory " << endl;
    cout << "17. PRESS 0 TO EXIT: " << endl;
}
int main()
{

    int choice;

    VEHICLE *car = new Car("Toyota", "Corolla", 2020, 25000, 4);
    VEHICLE *truck = new Truck("Ford", "F-150", 2021, 40000, "6ft");
    VEHICLE *bike = new MotorCycle("Harley-Davidson", "Sportster", 2018, 12000, 1600);
    INVENTORY in;
    in.addCar(car);
    in.addTruck(truck);
    in.addBike(bike);

    cout << " EXHIBITING POLYMORPHISM! " << endl;
    VEHICLE *ptr[3];
    ptr[0] = car;
    ptr[1] = truck;
    ptr[2] = bike;

    for (auto &vehicle : ptr)
    {
        vehicle->display_info();
        cout << endl;
    }
    cout << "-----WELCOME TO THE VEHCILES MANAGEMENT SYSTEM-------" << endl;
    cout << "What would you like to have? " << endl;
    do
    {
        menu();
        cout << "Enter Choice(1-16): ";
        cin >> choice;
        cout << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.fail() || choice > 16 || choice < 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong choice ): ENTER AGAIN!! " << endl;
        }
        else if (choice == 0)
        {
            cout << "BYE BYE! " << endl;
            exit(0);
        }
        else
        {

            if (choice == 1)
            {
                string make;
                string model;
                int year;
                double price;
                int doors;
                try
                {
                    cout << "Enter New Car Details: " << endl;
                    cout << "Enter Car Maker : ";
                    getline(cin, make);
                    cout << "Enter Car Model : ";
                    getline(cin, model);
                    cout << "Enter Year: ";
                    cin >> year;
                    cout << "Enter Price: ";
                    cin >> price;
                    cout << "Enter Number of Doors: ";
                    cin >> doors;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
                Car *new_car = new Car(make, model, year, price, doors);
                in.addCar(new_car);
                cout << "NEW CAR ADDED SUCCESSFULLY! " << endl;
            }
            else if (choice == 2)
            {
                string make;
                string model;
                int year;
                double price;
                string bedSize;
                try
                {
                    cout << "Enter New Truck Details: " << endl;
                    cout << "Enter Truck Maker : ";
                    getline(cin, make);

                    cout << "Enter Truck Model : ";
                    getline(cin, model);
                    cout << "Enter Year: ";
                    cin >> year;
                    cout << "Enter Price: ";
                    cin >> price;
                    cout << "Enter Truck Bed Size: ";
                    cin >> bedSize;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
                Truck *new_truck = new Truck(make, model, year, price, bedSize);
                in.addTruck(new_truck);
                cout << "NEW TRUCK ADDED SUCCESSFULLY! " << endl;
            }
            else if (choice == 3)
            {
                string make;
                string model;
                int year;
                double price;
                double engine;
                try
                {
                    cout << "Enter New Truck Details: " << endl;
                    cout << "Enter MotorCycle Maker : ";
                    getline(cin, make);

                    cout << "Enter MotorCycle Model : ";
                    getline(cin, model);
                    cout << "Enter Year: ";
                    cin >> year;
                    cout << "Enter Price: ";
                    cin >> price;
                    cout << "Enter MotorCycle Engnine Size: ";
                    cin >> engine;
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
                MotorCycle *new_bike = new MotorCycle(make, model, year, price, engine);
                in.addBike(new_bike);
                cout << "NEW MOTORCYCLE ADDED SUCCESSFULLY! " << endl;
            }
            else if (choice == 4)
            {
                string model;
                in.display_cars();
                cout << endl;
                try
                {
                    cout << "Enter Car Model To Remove(from above cars) : ";
                    getline(cin, model);
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
                in.removeCar(model);
            }
            else if (choice == 5)
            {
                string model;
                in.display_trucks();
                cout << endl;
                try
                {
                    cout << "Enter Truck Model To Remove(from above cars) : ";
                    getline(cin, model);
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
                in.removeTruck(model);
            }
            else if (choice == 6)
            {
                string model;
                in.display_bikes();
                cout << endl;
                try
                {
                    cout << "Enter Bike Model To Remove(from above cars) : ";
                    getline(cin, model);
                }
                catch (exception &e)
                {
                    cout << "ERROR! " << e.what() << endl;
                }
                in.removeBike(model);
            }
            else if (choice == 7)
            {

                in.searchCar();
            }
            else if (choice == 8)
            {
                in.searchTruck();
            }
            else if (choice == 9)
            {

                in.searchBike();
            }
            else if (choice == 10)
            {
                in.sortCar();
            }
            else if (choice == 11)
            {
                in.sortTruck();
            }
            else if (choice == 12)
            {
                in.sortBike();
            }
            else if (choice == 13)
            {
                in.display_cars();
            }
            else if (choice == 14)
            {
                in.display_trucks();
            }
            else if (choice == 15)
            {
                in.display_bikes();
            }
            else if (choice == 16)
            {
                in.display_all_inventory();
            }
        }
    } while (choice != 0 || choice > 16);
    delete car;
    delete bike;
    delete truck;
    return 0;
}