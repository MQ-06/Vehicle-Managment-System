#include "inventory.h"
INVENTORY::INVENTORY() : vehicles(nullptr), countVehicles(0) {}
INVENTORY::~INVENTORY()
{
    for (int i = 0; i < countVehicles; ++i)
    {
        delete vehicles[i];
    }
    delete[] vehicles;
}
void INVENTORY::addCar(VEHICLE *c)
{
    VEHICLE **temp = new VEHICLE *[countVehicles + 1];

    for (int i = 0; i < countVehicles; i++)
    {
        temp[i] = vehicles[i];
    }
    temp[countVehicles] = c;
    delete[] vehicles;
    vehicles = temp;
    countVehicles++;
}
void INVENTORY::addTruck(VEHICLE *t)
{
    VEHICLE **temp = new VEHICLE *[countVehicles + 1];
    for (int i = 0; i < countVehicles; i++)
    {
        temp[i] = vehicles[i];
    }
    temp[countVehicles] = t;
    delete[] vehicles;
    vehicles = temp;
    countVehicles++;
}
void INVENTORY::addBike(VEHICLE *m)
{
    VEHICLE **temp = new VEHICLE *[countVehicles + 1];
    for (int i = 0; i < countVehicles; i++)
    {
        temp[i] = vehicles[i];
    }
    temp[countVehicles] = m;
    delete[] vehicles;
    vehicles = temp;
    countVehicles++;
}

void INVENTORY::removeCar(string &model)
{
    int index = -1;
    bool find = false;

    for (int i = 0; i < countVehicles; i++)
    {
        Car *carPtr = dynamic_cast<Car *>(vehicles[i]);
        if (carPtr && carPtr->getModel() == model)
        {
            index = i;
            find = true;
            break;
        }
    }

    if (find && index != -1)
    {
        delete vehicles[index];
        for (int i = index; i < countVehicles - 1; i++)
        {
            vehicles[i] = vehicles[i + 1];
        }
    }

    if (!find)
    {
        cout << "CAR WITH MODEL " << model << " NOT FOUND! " << endl;
    }
    else
    {
        cout << "CAR WITH MODEL " << model << " REMOVED SUCCESSFULLY! " << endl;
    }

    countVehicles--;
}

void INVENTORY::removeTruck(string &model)
{
    int index = -1;
    bool find = false;

    for (int i = 0; i < countVehicles; i++)
    {
        Car *carPtr = dynamic_cast<Car *>(vehicles[i]);
        if (carPtr && carPtr->getModel() == model)
        {
            index = i;
            find = true;
            break;
        }
    }

    if (find && index != -1)
    {
        delete vehicles[index];
        for (int i = index; i < countVehicles - 1; i++)
        {
            vehicles[i] = vehicles[i + 1];
        }
    }

    if (!find)
    {
        cout << "TRUCK WITH MODEL " << model << " NOT FOUND! " << endl;
    }
    else
    {
        cout << "TRUCK WITH MODEL " << model << " REMOVED SUCCESSFULLY! " << endl;
    }

    countVehicles--;
}
void INVENTORY::removeBike(string &model)
{
    int index = -1;
    bool find = false;

    for (int i = 0; i < countVehicles; i++)
    {
        Car *carPtr = dynamic_cast<Car *>(vehicles[i]);
        if (carPtr && carPtr->getModel() == model)
        {
            index = i;
            find = true;
            break;
        }
    }

    if (find && index != -1)
    {
        delete vehicles[index];
        for (int i = index; i < countVehicles - 1; i++)
        {
            vehicles[i] = vehicles[i + 1];
        }
    }

    if (!find)
    {
        cout << "BIKE WITH MODEL " << model << " NOT FOUND! " << endl;
    }
    else
    {
        cout << "BIKE WITH MODEL " << model << " REMOVED SUCCESSFULLY! " << endl;
    }

    countVehicles--;
}
void INVENTORY::display_cars()
{
    if (countVehicles <= 0)
    {
        cout << "No cars to display";
        return;
    }
    cout << "Displaying all cars in inventory:" << endl;

    for (int i = 0; i < countVehicles; i++)
    {
        if (dynamic_cast<Car *>(vehicles[i]))
        {
            vehicles[i]->display_info();
            cout << endl;
        }
    }
}
void INVENTORY::display_trucks()
{
    if (countVehicles <= 0)
    {
        cout << "No trucks to display";
        return;
    }
    cout << "Displaying all trucks in inventory:" << endl;

    for (int i = 0; i < countVehicles; i++)
    {
        if (dynamic_cast<Truck *>(vehicles[i]))
        {
            vehicles[i]->display_info();
            cout << endl;
        }
    }
}
void INVENTORY::display_bikes()
{
    if (countVehicles <= 0)
    {
        cout << "No bikes to display";
        return;
    }
    cout << "Displaying all bikes in inventory:" << endl;

    for (int i = 0; i < countVehicles; i++)
    {
        if (dynamic_cast<MotorCycle *>(vehicles[i]))
        {
            vehicles[i]->display_info();
            cout << endl;
        }
    }
}
void INVENTORY::display_all_inventory()
{
    if (countVehicles <= 0)
    {
        cout << "No vehicles to display";
        return;
    }
    cout << "Displaying all vehicles in inventory:" << endl;

    for (int i = 0; i < countVehicles; i++)
    {
        vehicles[i]->display_info();
        cout << endl;
    }
}

void INVENTORY::searchCar()
{
    string key;

    string searchCriteria;
    cout << "Enter search criteria (make, model, year, price): ";
    cin >> searchCriteria;

    cout << "Enter key value: ";
    cin >> key;
    bool found = false;

    for (int i = 0; i < countVehicles; ++i)
    {
        if (searchCriteria == "make" && vehicles[i]->getMake() == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
        else if (searchCriteria == "model" && vehicles[i]->getModel() == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
        else if (searchCriteria == "year" && to_string(vehicles[i]->getYear()) == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
        else if (searchCriteria == "price" && to_string(vehicles[i]->getPrice()) == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "No vehicle found" << endl;
    }
}
void INVENTORY::searchTruck()
{
    string key;

    string searchCriteria;
    cout << "Enter search criteria (make, model, year, price): ";
    cin >> searchCriteria;

    cout << "Enter key value: ";
    cin >> key;
    bool found = false;

    for (int i = 0; i < countVehicles; ++i)
    {
        if (searchCriteria == "make" && vehicles[i]->getMake() == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
        else if (searchCriteria == "model" && vehicles[i]->getModel() == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
        else if (searchCriteria == "year" && to_string(vehicles[i]->getYear()) == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
        else if (searchCriteria == "price" && to_string(vehicles[i]->getPrice()) == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "No vehicle found" << endl;
    }
}
void INVENTORY::searchBike()
{
    string key;

    string searchCriteria;
    cout << "Enter search criteria (make, model, year, price): ";
    cin >> searchCriteria;

    cout << "Enter key value: ";
    cin >> key;
    bool found = false;

    for (int i = 0; i < countVehicles; ++i)
    {
        if (searchCriteria == "make" && vehicles[i]->getMake() == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
        else if (searchCriteria == "model" && vehicles[i]->getModel() == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
        else if (searchCriteria == "year" && to_string(vehicles[i]->getYear()) == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
        else if (searchCriteria == "price" && to_string(vehicles[i]->getPrice()) == key)
        {
            vehicles[i]->display_info();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "No vehicle found" << endl;
    }
}

void INVENTORY::sortCar()
{
    string search;

    cout << "Enter Criteria on which you want to search (make, model, price, year): ";
    cin >> search;

    if (search != "make" && search != "model" && search != "price" && search != "year")
    {
        cout << "INVALID INPUT" << endl;
        return;
    }

    for (int i = 0; i < countVehicles; i++)
    {
        for (int j = 0; j < countVehicles; j++)
        {
            if (search == "make" && vehicles[i]->getMake() > vehicles[j]->getMake())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
            else if (search == "model" && vehicles[i]->getModel() > vehicles[j]->getModel())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
            else if (search == "year" && vehicles[i]->getYear() > vehicles[j]->getYear())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
            else if (search == "price" && vehicles[i]->getPrice() > vehicles[j]->getPrice())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
        }
    }
    cout << "Cars sorted in ascending order! " << endl;
}

void INVENTORY::sortTruck()
{
    string search;

    cout << "Enter Criteria on which you want to search (make, model, price, year): ";
    cin >> search;

    if (search != "make" && search != "model" && search != "price" && search != "year")
    {
        cout << "INVALID INPUT" << endl;
        return;
    }

    for (int i = 0; i < countVehicles; i++)
    {
        for (int j = 0; j < countVehicles; j++)
        {
            if (search == "make" && vehicles[i]->getMake() > vehicles[j]->getMake())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
            else if (search == "model" && vehicles[i]->getModel() > vehicles[j]->getModel())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
            else if (search == "year" && vehicles[i]->getYear() > vehicles[j]->getYear())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
            else if (search == "price" && vehicles[i]->getPrice() > vehicles[j]->getPrice())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
        }
    }

    cout << "Trucks sorted in ascending order! " << endl;
}
void INVENTORY::sortBike()
{
    string search;

    cout << "Enter Criteria on which you want to search (make, model, price, year): ";
    cin >> search;

    if (search != "make" && search != "model" && search != "price" && search != "year")
    {
        cout << "INVALID INPUT" << endl;
        return;
    }

    for (int i = 0; i < countVehicles; i++)
    {
        for (int j = 0; j < countVehicles; j++)
        {
            if (search == "make" && vehicles[i]->getMake() > vehicles[j]->getMake())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
            else if (search == "model" && vehicles[i]->getModel() > vehicles[j]->getModel())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
            else if (search == "year" && vehicles[i]->getYear() > vehicles[j]->getYear())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
            else if (search == "price" && vehicles[i]->getPrice() > vehicles[j]->getPrice())
            {
                VEHICLE *temp = vehicles[i];
                vehicles[i] = vehicles[j];
                vehicles[j] = temp;
            }
        }
    }
    cout << "Bikes sorted in ascending order! " << endl;
}