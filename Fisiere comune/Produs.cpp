#include<string>
#include<iostream>
#include <windows.h>
#include "Produs.h"
#include "Culori.h"

void set_color(int color_code) {
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hconsole, color_code);
}

Produs::Produs() {
    this->id_produs = 0;
    this->nume_produs = "";
    this->cantitate = 0;
    this->pret = 0;
}

Produs::Produs(int id_produs, std::string nume_produs, int cantitate, double pret) {
    this->id_produs = id_produs;
    this->nume_produs = nume_produs;
    this->cantitate = cantitate;
    this->pret = pret;
    //nr_produse++;
}

Produs::Produs(const Produs &x){
    this->id_produs = x.id_produs;
    this->nume_produs = x.nume_produs;
    this->cantitate = x.cantitate;
    this->pret = x.pret;
    //nr_produse++;
}

Produs::~Produs(){
    //nr_produse--;
}

std::istream& operator>>(std::istream &in, Produs &x){
    in >> x.id_produs;
    in.ignore();
    getline(in, x.nume_produs);
    in >> x.cantitate >> x.pret;
    return in;
}

std::ostream& operator<<(std::ostream &out, const Produs &x){
    set_color(WHITE);
    out << x.id_produs << "\n" << x.nume_produs << "\n" << x.cantitate << " " << x.pret;
    return out;
}

Produs& Produs::operator+=(int x){
    this->cantitate += x;
    return *this;
}

Produs& Produs::operator++(){
    this->cantitate++;
    return *this;
}

Produs Produs::operator++(int x){
    Produs a = *this;
    this->cantitate++;
    return a;
}

void Produs::afisare() {
    set_color(WHITE);
    std::cout << "                                           ";
    std::cout << this->id_produs << " " << this->nume_produs << " " << this->cantitate << " " << this->pret << "\n";
}

int Produs::get_id() {
    return this->id_produs;
}

std::string Produs::get_nume() {
    return this->nume_produs;
}

int Produs::get_cantitate() {
    return this->cantitate;
}

double Produs::get_pret() {
    return this->pret;
}

void Produs::set_id(int x) {
    this->id_produs = x;
}

void Produs::set_nume(std::string x) {
    this->nume_produs = x;
}

void Produs::set_cantitate(int x) {
    this->cantitate = x;
}

void Produs::set_pret(double x) {
    this->pret = x;
}

