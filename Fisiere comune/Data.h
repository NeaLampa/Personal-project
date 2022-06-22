#pragma once

class Data{
private:
    int zi;
    int luna;
    int an;
public:
    Data();
    Data(int, int, int);
    Data(const Data&);
    ~Data();
    friend std::istream& operator>>(std::istream&, Data&);
    friend std::ostream& operator<<(std::ostream&, const Data&);
};
