#include <iostream>

using namespace std;


// Product Class
class Car {
public:
    virtual void drive() = 0;
    virtual ~Car() {}
};


// Toyota Cars
class ToyotaEconomyCar : public Car {
public:
    void drive() override {
        cout << "Driving Toyota Economy Car with basic features!" << endl;
    }
};

class ToyotaFamilyCar : public Car {
public:
    void drive() override {
        cout << "Driving Toyota Family Car with comfortable interior and safety features!" << endl;
    }
};

class ToyotaLuxuryCar : public Car {
public:
    void drive() override {
        cout << "Driving Toyota Luxury Car with premium interior and advanced features!" << endl;
    }
};


// BMW Cars
class BMWEconomyCar : public Car {
public:
    void drive() override {
        cout << "Driving BMW Economy Car with efficient engine and basic features!" << endl;
    }
};

class BMWFamilyCar : public Car {
public:
    void drive() override {
        cout << "Driving BMW Family Car with comfortable interior and safety features!" << endl;
    }
};

class BMWLuxuryCar : public Car {
public:
    void drive() override {
        cout << "Driving BMW Luxury Car with premium interior and advanced features!" << endl;
    }
};


// Factory
class CarFactory {
public:
    virtual Car* createCar(string& type) = 0;
    virtual ~CarFactory() {}
};


// Toyota Factory
class ToyotaFactory : public CarFactory {
public:

    Car* createCar(string& type) override {

        if (type == "economy") {
            return new ToyotaEconomyCar();

        } else if (type == "family") {
            return new ToyotaFamilyCar();

        } else if (type == "luxury") {
            return new ToyotaLuxuryCar();

        } else {
            cout << "Invalid Toyota car type!" << endl;
            return nullptr;
        }
    }
};


// BMW Factory
class BMWFactory : public CarFactory {
public:

    Car* createCar(string& type) override {

        if (type == "economy") {
            return new BMWEconomyCar();

        } else if (type == "family") {
            return new BMWFamilyCar();

        } else if (type == "luxury") {
            return new BMWLuxuryCar();

        } else {
            cout << "Invalid BMW car type!" << endl;
            return nullptr;
        }
    }
};


int main() {

    string brand;
    string carType;

    cout << "Enter car brand (toyota/bmw): ";
    cin >> brand;

    cout << "Enter car type (economy/family/luxury): ";
    cin >> carType;


    CarFactory* carFactory;


    if (brand == "toyota") {
        carFactory = new ToyotaFactory();

    } else if (brand == "bmw") {
        carFactory = new BMWFactory();

    } else {
        cout << "Invalid car brand!" << endl;
        return 0;
    }


    Car* car = carFactory->createCar(carType);


    if (car != nullptr) {
        car->drive();
    }


    delete car;
    delete carFactory;

    return 0;
}
