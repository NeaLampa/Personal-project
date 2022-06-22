#pragma once

void set_color(int color_code);

class Produs{
private:
    //static int nr_produse;
    int id_produs;
    std::string nume_produs;
    int cantitate;
    double pret;
public:
    Produs();
    Produs(int, std::string, int, double);
    Produs(const Produs &);
    ~Produs();
    friend std::istream& operator>>(std::istream &, Produs &);
    friend std::ostream& operator<<(std::ostream &, const Produs &);
    Produs& operator+=(const int x);
    Produs& operator++();
    Produs operator++(int);
    void afisare();
    int get_id();
    std::string get_nume();
    int get_cantitate();
    double get_pret();
    void set_id(int);
    void set_nume(std::string);
    void set_cantitate(int);
    void set_pret(double);
};
