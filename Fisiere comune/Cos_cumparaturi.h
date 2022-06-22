#pragma once

#include "C:\Users\pasca\Desktop\Chestii C++\PP-final\Fisiere comune\Data.h"

class Cos_cumparaturi {
private:
	int numar_produse;
	std::vector<Produs>lista_cumparaturi;
	Data data;
public:
	Cos_cumparaturi();
	Cos_cumparaturi(int, std::vector<Produs>, Data);
	Cos_cumparaturi(const Cos_cumparaturi&);
	~Cos_cumparaturi();
	friend std::ostream& operator<<(std::ostream&, const Cos_cumparaturi&);
	void afisare();
	std::vector<Produs> get_lista();
	void append(Produs x);
	void stergere_produs(Produs x);
	void set_cantitate(Produs x, int cantitate);
};