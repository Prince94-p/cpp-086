#include <iostream>
using namespace std;

class Fuel {
protected:
    string fuelType;

public:
    Fuel(string f) {
        fuelType = f;
    }
};

class Brand {
protected:
    string brandName;

public:
    Brand(string b) {
        brandName = b;
    }
};

class Car : public Fuel, public Brand {
private:
    int carID;

public:
    Car(int id, string f, string b) : Fuel(f), Brand(b) {
        carID = id;
    }

    void show() {
        cout << "Car ID: " << carID << endl;
        cout << "Brand: " << brandName << endl;
        cout << "Fuel: " << fuelType << endl;
        cout << "----------------------" << endl;
    }
};

void run(Car c[], int n) {
    cout << "\nCars:\n";
    for (int i = 0; i < n; i++) {
        c[i].show();
    }
}

void simple() {
    cout << "\nStatic:\n";

    Car c1(1, "Petrol", "Toyota");
    Car c2(2, "Diesel", "Hyundai");
    Car c3(3, "Electric", "Tesla");

    c1.show();
    c2.show();
    c3.show();
}

int main() {
    Car c[3] = {
        Car(1, "Petrol", "Toyota"),
        Car(2, "Diesel", "Hyundai"),
        Car(3, "Electric", "Tesla")
    };

    run(c, 3);
    simple();

    return 0;
}