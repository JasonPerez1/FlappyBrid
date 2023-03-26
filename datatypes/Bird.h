#ifndef _BIRD_H_
#define _PIRD_H_

#include <iostream>
#include <string>
#include "Pair.h"
using namespace std;
class Bird {
public:
    // default constructor
    Bird();

    // explicit-value constructor
    Bird(Pair<double> l, double v, double a);

    // getters
    Pair<double> getLocation() const;
    double getVelocity() const;
    double getAcceleration() const;

    // setters

    void setLocation(Pair<double> newPair);
    void setVelocity(double v);
    void setAcceleration(double a);

    // string
    string toString() const;

    //update bird
    void moveBird();
public:
    Pair<double> location;
    double velocity;
    double acceleration;
};

// default constructor
Bird::Bird() {
    location.setFirst(1);
    location.setSecond(5);

    velocity = 0.0;
    acceleration = 1.0;
}

// explicit-value constructor
Bird::Bird(Pair<double> l, double v, double a) {
    location.setFirst(l.getFirst());
    location.setSecond(l.getSecond());

    velocity = v;
    acceleration = a;
}


//getters
Pair<double> Bird::getLocation() const {
    return location;
}
double Bird::getVelocity() const{
    return velocity;
}

double Bird::getAcceleration() const{
    return acceleration;
}

//setters
void Bird::setLocation(Pair<double> newPair) {
    location.setFirst(newPair.getFirst());
    location.setSecond(newPair.getSecond());
}
void Bird::setVelocity(double v) {
    velocity = v;
}
void Bird::setAcceleration(double a) {
    acceleration = a;
}

string Bird::toString() const {
    return "l<" + to_string(location.getFirst()) + ", " + to_string(location.getSecond()) + ">"+
            "v " + to_string(velocity) + "a " + to_string(acceleration);
}

ostream &operator<<(ostream &out, const Bird &p) {
    out << p.toString();
    return out;
}

void Bird::moveBird(){
    location.setSecond(location.getSecond()+velocity);
    velocity = velocity + acceleration;
}

// template <class string>
// template <>
// string Pair<string>::toString() const {
    // return "<" + myFirst + ", " + mySecond + ">";
// }

#endif
