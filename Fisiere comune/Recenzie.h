#pragma once

#include "Data.h"

class Recenzie {
private:
	std::string recenzie;
	Data data_recenzie;
public:
	Recenzie();
	Recenzie(std::string, Data);
	Recenzie(const Recenzie &);
	~Recenzie();
	friend std::istream& operator>>(std::istream&, Recenzie&);
	friend std::ostream& operator<<(std::ostream&, const Recenzie&);
	Recenzie(std::string recenzie);
};
