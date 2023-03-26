#ifndef _PIPE_H_
#define _PIPE_H_

#include <iostream>
#include <string>
#include "Pair.h"
using namespace std;
class Pipe {
public:
    // default constructor
    Pipe();

    // explicit-value constructor
    Pipe(Pair<int> bl, int g, int w, int d);

    // getters
    Pair<int> getBottomLeft() const;
    int getGap() const;
    int getWidth() const;

    // setters
    void setBottomLeft(Pair<int> newPair);
    void setGap(int g);
    void setWidth(int w);

    // string
    string toString() const;

    // check if the entered pair has is inbetween the x values of the pipe
    bool xinside(Pair<int> newpair) const;
    // check if the entered pair has is inbetween the x values of the pipe
    bool yinside(Pair<int> newpair) const;

    //increment the pipe left
    void pipeleft();
public:
    Pair<int> bottomLeft;
    int gap;
    int width;
    int distanceleft = 1;
};

// default constructor
Pipe::Pipe() {
    bottomLeft.setFirst(0);
    bottomLeft.setSecond(0);

    gap = 6;
    width = 1;
    distanceleft = 1;
}

// explicit-value constructor
Pipe::Pipe(Pair<int> bl, int g, int w, int d) {
    bottomLeft.setFirst(bl.getFirst());
    bottomLeft.setSecond(bl.getSecond());

    gap = g;
    width = w;
    distanceleft = d;
}


//getters

Pair<int> Pipe::getBottomLeft() const {
    return bottomLeft;
}
int Pipe::getGap() const{
    return gap;
}

int Pipe::getWidth() const{
    return width;
}

//setters
void Pipe::setBottomLeft(Pair<int> newPair) {
    bottomLeft.setFirst(newPair.getFirst());
    bottomLeft.setSecond(newPair.getSecond());
}
void Pipe::setGap(int g) {
    gap = g;
}
void Pipe::setWidth(int w) {
    width = w;
}

string Pipe::toString() const {
    return "bl<" + to_string(getBottomLeft().getFirst()) + ", " + to_string(getBottomLeft().getSecond()) + ">"+
            "g " + to_string(gap) + "w " + to_string(width);
}

ostream &operator<<(ostream &out, const Pipe &p) {
    out << p.toString();
    return out;
}

// check if the entered pair has is inbetween the x values of the pipe
bool Pipe::xinside(Pair<int> newpair) const{
    if (newpair.getFirst() <= bottomLeft.getFirst() ||
        newpair.getFirst() >= bottomLeft.getFirst() + gap){
        return false;
    }
    return true;
}
// check if the entered pair has is inbetween the x values of the pipe
bool Pipe::yinside(Pair<int> newpair) const{
    if (newpair.getFirst() <= bottomLeft.getSecond() ||
        newpair.getFirst() >= bottomLeft.getSecond() + gap){
        return false;
    }
    return true;
    }

void Pipe::pipeleft(){
    bottomLeft.setFirst(bottomLeft.getFirst()-distanceleft);
}

// template <class string>
// template <>
// string Pair<string>::toString() const {
    // return "<" + myFirst + ", " + mySecond + ">";
// }

#endif
