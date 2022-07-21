#include <iostream>
#include <vector>
#include <windows.h>
#include "C:\Users\pasca\Desktop\Chestii C++\Proiect personal\Fisiere comune\Culori.h"
#include "C:\Users\pasca\Desktop\Chestii C++\Proiect personal\Fisiere comune\Produs.h"
#include "C:\Users\pasca\Desktop\Chestii C++\Proiect personal\Fisiere comune\Data.h"
#include "C:\Users\pasca\Desktop\Chestii C++\Proiect personal\Fisiere comune\Cos_cumparaturi.h"
#include "C:\Users\pasca\Desktop\Chestii C++\Proiect personal\Fisiere comune\Recenzie.h"


Cos_cumparaturi::Cos_cumparaturi() {
	this->numar_produse = 0;
	this->lista_cumparaturi = {};
	this->data = {};
}

Cos_cumparaturi::Cos_cumparaturi(int numar_produse, std::vector<Produs>produse, Data data) {
	this->numar_produse = numar_produse;
	this->lista_cumparaturi = produse;
	this->data = data;
}

Cos_cumparaturi::Cos_cumparaturi(const Cos_cumparaturi &x) {
	this->numar_produse = x.numar_produse;
	this->lista_cumparaturi = x.lista_cumparaturi;
	this->data = x.data;
}

void Cos_cumparaturi::append(Produs x) {
	this->lista_cumparaturi.push_back(x);
}

Cos_cumparaturi::~Cos_cumparaturi() {

}

std::vector<Produs> Cos_cumparaturi::get_lista() {
	return this->lista_cumparaturi;
}

std::ostream& operator<<(std::ostream &out, const Cos_cumparaturi &x) {
	out << x.data << std::endl << x.lista_cumparaturi.size() << std::endl;
	for (auto& produse : x.lista_cumparaturi) {
		out << produse << "\n";
	}
	out << "\n";
	return out;
}

void Cos_cumparaturi::afisare() {
	set_color(WHITE);
	std::cout << "                                           ";
	std::cout << this->data << std::endl;
	for (auto& produs : this->lista_cumparaturi) {
		std::cout << "                                           ";
		std::cout << produs.get_id() << " " << produs.get_nume() << " " << produs.get_cantitate() << std::endl;
	}
}

void Cos_cumparaturi:: stergere_produs(Produs x) {
	int id = x.get_id();
	int index=-1;
	for (auto& produs : this->lista_cumparaturi) {
		index++;
		if (produs.get_id() == id) {
			this->lista_cumparaturi.erase(this->lista_cumparaturi.begin()+index);
			break;
		}
	}
}
void Cos_cumparaturi:: set_cantitate(Produs x,int cantitate) {
	int id = x.get_id();
	int index = -1;
	for (auto& produs : this->lista_cumparaturi) {
		index++;
		if (produs.get_id() == id) {
			produs.set_cantitate(cantitate);
			break;
		}
	}
}

