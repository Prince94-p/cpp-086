#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int empID;

public:
    Employee(string n, int a, int id) : Person(n, a) {
        empID = id;
    }

    void displayEmployee() {
        cout << "Employee ID: " << empID << endl;
    }

    int getID() {
        return empID;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id) {
        department = dept;
    }

    void displayManager() {
        displayPerson();
        displayEmployee();
        cout << "Department: " << department << endl;
        cout << "----------------------" << endl;
    }
};

void searchManager(Manager m[], int size, int id) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (m[i].getID() == id) {
            cout << "\nManager Found:\n";
            m[i].displayManager();
            found = 1;
            break;
        }
    }

    if (found == 0) {
        cout << "\nManager not found\n";
    }
}

void staticManagers() {
    cout << "\nStatic Managers:\n";

    Manager m1("Prince", 21, 101, "HR");
    Manager m2("Dwij", 22, 102, "IT");
    Manager m3("Smit", 23, 103, "Finance");

    m1.displayManager();
    m2.displayManager();
    m3.displayManager();
}

int main() {
    Manager m[3] = {
        Manager("Prince", 21, 101, "HR"),
        Manager("Dwij", 22, 102, "IT"),
        Manager("Smit", 23, 103, "Finance")
    };

    cout << "All Managers:\n";
    for (int i = 0; i < 3; i++) {
        m[i].displayManager();
    }

    int id;
    cout << "\nEnter Employee ID to search: ";
    cin >> id;

    searchManager(m, 3, id);

    staticManagers();

    return 0;
}
