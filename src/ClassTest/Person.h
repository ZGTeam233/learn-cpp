#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
public:
    Person() = default;
    Person(int a, std::string n) : age(a), name(n) {}
    void eat() const {
        std::cout << name << " is eating. He is " << age << " years old.\n" << std::endl;
    }
    int getAge() const { return age; }
    std::string getName() const { return name; }
    void setAge(int a) { age = a; }
    void setName(std::string n) { name = n; }
private:
    int age = 0;
    std::string name;
};

#endif // PERSON_H