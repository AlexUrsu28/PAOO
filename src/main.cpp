#include <iostream>
#include <string>
#include <utility> // Include for std::move

using namespace std;

class Car {
private:
    string* name; // Pointer către un string alocat dinamic
    int speed;

public:
    // Constructor cu parametri
    Car(const string& carName, int carSpeed) {
        name = new string(carName);  // Alocare pe heap
        speed = carSpeed;
        cout << "Constructor called for " << *name << endl;
    }

    // Copy constructor
    Car(const Car& other) {
        name = new string(*other.name);  // Copiere profundă
        speed = other.speed;
        cout << "Copy constructor called for " << *name << endl;
    }

    // Move constructor
    Car(Car&& other) noexcept {
        name = other.name;       // Transfer de pointer
        speed = other.speed;
        other.name = nullptr;    // Anulăm pointerul vechi
        cout << "Move constructor called for " << *name << endl;
    }

    // Destructor
    ~Car() {
        if (name) {
            delete name; // Eliberare a memoriei alocate pe heap
        }
        cout << "Destructor called" << endl;
    }

    // Metodă de afișare
    void display() const {
        if (name) {
            cout << "Car: " << *name << ", Speed: " << speed << " km/h" << endl;
        }
    }
};

int main() {
    Car car1("Toyota", 120);
    car1.display();

    Car car2 = car1;
    car2.display();

    Car car3 = std::move(car1);
    car3.display();

    return 0;
}
