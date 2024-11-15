#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string name;
    int speed;

    Car(const Car& other) {
        name = other.name;  // Copiere profundă
        speed = other.speed;
        cout << "Copy constructor called for " << name << endl;
    }
public:
    Car(const string carName = "Unknown", int carSpeed = 0) 
        //Initializer list - Item3
        : name(carName), speed(carSpeed) {
        cout << "Constructor apelat pentru " << name << endl;
    }

    void display() const {
        cout << "Car: " << name << ", Speed: " << speed << " km/h" << endl;
    }    
};

int main() {
    const Car car1("Toyota", 120); // Corect inițializat
    car1.display();

    Car car2; // Constructorul implicit va seta "Unknown" pentru name și 0 pentru speed
    car2.display();
    
    Car car3;
    car3 = car1; // copy assignment op nu este implementat explicit si totusi functioneaza ITEM 5
    car3.display();

    // Car car4 = car3; => Car car4(car3);
    // deoarece copy constructor este private nu se poate folosi in afara scopului clasei
    return 0;
}
