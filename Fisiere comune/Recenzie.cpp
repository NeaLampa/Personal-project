#include <string>
#include <iostream>
#include "Recenzie.h"
#include "Data.h"

Recenzie::Recenzie() {
	//this->recenzie = NULL;
	this->data_recenzie = {};
}

Recenzie::Recenzie(std::string recenzie, Data data_recenzie) {
	this->recenzie = recenzie;
	this->data_recenzie = data_recenzie;
}

Recenzie::Recenzie(std::string recenzie) {
	this->recenzie = recenzie;
	this->data_recenzie = {};
}

Recenzie::Recenzie(const Recenzie& x) {
	this->recenzie = x.recenzie;
	this->data_recenzie = x.data_recenzie;
}

Recenzie::~Recenzie() {

}

std::istream& operator>>(std::istream &in, Recenzie &x) {
	getline(in, x.recenzie);
	in >> x.data_recenzie;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Recenzie& x) {
	out << x.recenzie << "\n" << x.data_recenzie;
	return out;
}
