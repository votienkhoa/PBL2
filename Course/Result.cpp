#include"Result.h"

Result::Result()
    : TX(0), GK(0), CK(0)
{
}

Result::~Result(){

}

double Result::getTX() const{
    return TX;
}

double Result::getGK() const{
    return GK;
}

double Result::getCK() const{
    return CK;
}