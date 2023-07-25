#include <iostream>
#include <string>

// Base Class
class Vehicle
{
    public:
        void honk();
    
    protected:
        std::string vehicle_brand = "Ford";
};

void Vehicle::honk()
{
    std::cout << "Honk!" << std::endl;
}
// ===========================================================

// Other Base Class
class OtherVehicle
{
    public:
        void other_honk();

    protected:
        std::string other_vehicle_brand = "Other Ford";
        
};

void OtherVehicle::other_honk()
{
    std::cout << "Other Honk!" << std::endl;
}
// ===========================================================


// Derived Class
class Car : public Vehicle, public OtherVehicle
{
    public:
        std::string get_vehicle();
        void set_vehicle(std::string new_vehicle);
        std::string get_other_vehicle();
        void set_other_vehicle(std::string new_other_vehicle);
        std::string get_car();
        void set_car(std::string new_car);
        void honk();

    protected:
        std::string car_model = "F-150";
};

std::string Car::get_vehicle()
{
    return vehicle_brand;
}

void Car::set_vehicle(std::string new_vehicle)
{
    vehicle_brand = new_vehicle;
}

std::string Car::get_other_vehicle()
{
    return other_vehicle_brand;
}

void Car::set_other_vehicle(std::string new_other_vehicle)
{
    other_vehicle_brand = new_other_vehicle;
}

std::string Car::get_car()
{
    return car_model;
}

void Car::set_car(std::string new_car)
{
    car_model = new_car;
}

// Polymorphism
void Car::honk()
{
    std::cout << "Honk Honk!" << std::endl;
}
// ===========================================================


int main(void)
{
    Vehicle myVehicle;
    Car myCar;

    myVehicle.honk();
    myCar.honk();
    myCar.other_honk();
    std::cout << std::endl;
    
    // {std::string}.c_str() is needed when using printf (C++11)
    printf("Vehicle=%s, OtherVehicle=%s, Car=%s \n", myCar.get_vehicle().c_str(), myCar.get_other_vehicle().c_str(), myCar.get_car().c_str());

    myCar.set_vehicle("Toyota");
    printf("Vehicle=%s, OtherVehicle=%s, Car=%s \n", myCar.get_vehicle().c_str(), myCar.get_other_vehicle().c_str(), myCar.get_car().c_str());

    myCar.set_other_vehicle("Lexus");
    printf("Vehicle=%s, OtherVehicle=%s, Car=%s \n", myCar.get_vehicle().c_str(), myCar.get_other_vehicle().c_str(), myCar.get_car().c_str());

    myCar.set_car("ES-330");
    printf("Vehicle=%s, OtherVehicle=%s, Car=%s \n", myCar.get_vehicle().c_str(), myCar.get_other_vehicle().c_str(), myCar.get_car().c_str());

    return 0;
}