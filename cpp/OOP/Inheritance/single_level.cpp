#include<iostream>
using namespace std;

//inheritance is a process in which one object acquuires all the properties and behaviours of its parent object automatically, in suc a way, we can reuse, extend or modify the attributes and behaviours which are defined in the other class.

//advantage: reusability

//single level - when one class inherits another class.

class Animal{
    public:
    void eat(){
        cout << "Animal is eating" << endl;
    }

    void sleep(){
        cout << "Animal is sleeping" << endl;
    }
};

class Dog : public Animal{
    public:
    void bark(){
        cout << "Dog is barking" << endl;
    }
};

int main(){
    Dog d1;

    d1.eat();
}