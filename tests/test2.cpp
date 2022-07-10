#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* INTEGER agruments */
void ifun1(int x)    // takes pass-by-value + no-modification
{
    return;
}
void ifun2(int *x)   // takes pass-by-reference + no-modification
{
    return;
}
void ifun3(int x)    // takes pass-by-value + modification
{
    x = 3;
    return;
}
void ifun4(int *x)   // takes pass-by-reference + modification
{
    *x = 3;
    return;
}

/* CHARACTER arguments */
void cfun1(char x)    // takes pass-by-value + no-modification
{
    return;
}
void cfun2(char *x)   // takes pass-by-reference + no-modification
{
    return;
}
void cfun3(char x)    // takes pass-by-value + modification
{
    x = 'a';
    return;
}
void cfun4(char *x)   // takes pass-by-reference + modification
{
    *x = 'a';
    return;
}

/* STRING arguments */
void sfun1(std::string x)    // takes pass-by-value + no-modification
{
    return;
}
void sfun2(std::string *x)   // takes pass-by-reference + no-modification
{
    return;
}
void sfun3(std::string x)    // takes pass-by-value + modification
{
    x = "hello";
    return;
}
void sfun4(std::string *x)   // takes pass-by-reference + modification
{
    *x = "hello";
    return;
}

/* VECTOR arguments */
void vfun1(std::vector<int> x)    // takes pass-by-value + no-modification
{
    return;
}
void vfun2(std::vector<int> *x)   // takes pass-by-reference + no-modification
{
    return;
}
void vfun3(std::vector<int> x)    // takes pass-by-value + modification
{
    std::vector<int> r{1,2,3,4,5};
    x = r;
    return;
}
void vfun4(std::vector<int> *x)   // takes pass-by-reference + modification
{
    std::vector<int> r{1,2,3,4,5};
    *x = r;
    return;
}

/* CUSTOM CLASS arguments */
class Car {
private:
    int weight;
    std::string color;

public:
    int maxSpeed;
    // constructor
    Car() {
        weight = 1000;
        color = "red";
        maxSpeed = 80;
    }
    Car(int weight, std::string color) {
        this->weight = weight;
        this->color = color;
    }

    // other functions
    void printColor() {
        cout << "Color of car is: " << this->color << endl;
    }
    int getWeight() {
        return this->weight;
    }
    void class_fun1(int x) {    // pass-by-value + no-modification
        return;
    }
    void class_fun2(int x) {    // pass-by-value + modification
        x = 3;
    }
};
void class_modify_fun1(Car mycar) {
    mycar.printColor();
    mycar.maxSpeed = 100;
}
void class_modify_fun2(Car *mycar) {
    cout << "My car's weight is: " << mycar->getWeight() << endl;
}
void class_modify_fun3(Car mycar) {
    auto myNewcar = new Car(2000, "red");
    mycar = *myNewcar;
}
void class_modify_fun4(Car *mycar) {
    auto myNewcar = new Car(2000, "red");
    myNewcar->maxSpeed = 100;
    mycar = myNewcar;
}

int main()
{
    return 0;
}
