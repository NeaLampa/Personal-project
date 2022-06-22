#include<iostream>
#include "Data.h"
#include <ctime>


int get_zi()
{
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    int zi = 0 + newtime.tm_mday;
    return zi;
}

int get_luna()
{
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    int luna = 1 + newtime.tm_mon;
    return luna;
}

int get_an()
{
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    int an = 1900 + newtime.tm_year;
    return an;
}


Data::Data() {
    this->zi = get_zi();
    this->luna = get_luna();
    this->an = get_an();
}

Data::Data(int zi, int luna, int an){
    this->zi = zi;
    this->luna = luna;
    this->an = an;
}

Data::Data(const Data &x){
    this->zi = x.zi;
    this->luna = x.luna;
    this->an = x.an;
}

Data::~Data(){

}

std::istream& operator>>(std::istream &in, Data &x){
    in >> x.zi >> x.luna >> x.an;
    return in;
}

std::ostream& operator<<(std::ostream &out, const Data &x){
    out << x.zi << " " << x.luna << " " << x.an;
    return out;
}

