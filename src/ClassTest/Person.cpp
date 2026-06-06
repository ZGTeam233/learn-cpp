#include <iostream>
#include "Person.h"

std::istream &read(std::istream &is, Person &p) {
    is >> p.age >> p.name;
    return is;
}

std::ostream &print(std::ostream &os, const Person &p) {
    os << p.name << " (" << p.age << ")";
    return os;
}

Person::Person(std::istream &is) {
    read(is, *this);
}