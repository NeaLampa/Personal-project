#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Functii-mm.h"
#include "Headers.h"


void print_default() {
    system("cls");
    set_color(GREY);
    std::cout << "\n\n\n                                     -------------";
    set_color(BLUE);
    std::cout << "MANAGER MAGAZIN";
    set_color(GREY);
    std::cout << "-------------\n\n";
}

void select_(int realPos, int pos) {
    if (realPos == pos) {
        set_color(GREEN);
        std::cout << "                                         -->";
        set_color(WHITE);
    }
    else {
        std::cout << "                                           ";
    }
}

bool revenire(std::string submeniu) {
    int pos = 1;
    Sleep(120);
    while (TRUE) {
        print_default();
        set_color(WHITE);
        std::cout << submeniu;
        set_color(GREY);
        printf("      "); select_(1, pos); printf(" Da \n");
        set_color(GREY);
        printf("      "); select_(2, pos); printf(" Nu \n");
        set_color(GREY);
        system("pause>nul");
        if (GetAsyncKeyState(VK_DOWN) && pos != 2) {
            pos++;
        }
        else if (GetAsyncKeyState(VK_UP) && pos != 1) {
            pos--;
        }
        else if (GetAsyncKeyState(VK_RETURN)) {
            Sleep(120);
            if (pos == 1) {
                return TRUE;
            }
            else {
                return FALSE;
            }
        }
    }


}

void meniu_actualizare() {
    bool ok = TRUE;
    int pos = 1;
    std::string nume = "\n                                           Revenire la meniul de actualizare?\n";
    while (ok) {
        print_default();
        set_color(GREY);
        select_(1, pos); printf(" ID \n");
        set_color(GREY);
        select_(2, pos); printf(" Nume \n");
        set_color(GREY);
        select_(3, pos); printf(" Cantitate \n");
        set_color(GREY);
        select_(4, pos); printf(" Pret \n");
        set_color(GREY);
        select_(5, pos); printf(" Intoarecere la meniul de modificare \n");
        set_color(GREY);
        system("pause>nul");
        if (GetAsyncKeyState(VK_DOWN) && pos != 5) {
            pos++;
        }
        else if (GetAsyncKeyState(VK_UP) && pos != 1) {
            pos--;
        }
        else if (GetAsyncKeyState(VK_RETURN)) {
            switch (pos) {
            case 1:
                print_default();
                modificare_id();
                ok = revenire(nume);
                break;
            case 2:
                print_default();
                modificare_nume();
                ok = revenire(nume);
                break;
            case 3:
                print_default();
                modificare_cantitate();
                ok = revenire(nume);
                break;
            case 4:
                print_default();
                modificare_pret();
                ok = revenire(nume);
                break;
            case 5:
                print_default();
                ok = 0;
                break;
            default:
                print_default();
                std::cout << "nu trebuia sa ajungi aici";
                break;
            }
        }
    }
}

void meniu_modificare() {
    bool ok = TRUE;
    int pos = 1;
    std::string nume = "\n                                           Revenire la meniul de modificare?\n";
    while (ok) {
        print_default();
        set_color(GREY);
        select_(1, pos); printf(" Adaugare \n");
        set_color(GREY);
        select_(2, pos); printf(" Stergere \n");
        set_color(GREY);
        select_(3, pos); printf(" Actualizare Date \n");
        set_color(GREY);
        select_(4, pos); printf(" Intoarecere la meniul principal \n");
        set_color(GREY);
        system("pause>nul");
        if (GetAsyncKeyState(VK_DOWN) && pos != 4) {
            pos++;
        }
        else if (GetAsyncKeyState(VK_UP) && pos != 1) {
            pos--;
        }
        else if (GetAsyncKeyState(VK_RETURN)) {
            switch (pos) {
            case 1:
                print_default();
                adaugare_stoc();
                ok = revenire(nume);
                break;
            case 2:
                print_default();
                stergere_stoc();
                ok = revenire(nume);
                break;
            case 3:
                print_default();
                meniu_actualizare();
                ok = revenire(nume);
                break;
            case 4:
                print_default();
                ok = 0;
                break;
            default:
                print_default();
                std::cout << "nu trebuia sa ajungi aici";
                break;
            }
        }
    }
}

void meniu() {
    bool ok = TRUE;
    int pos = 1;
    std::string nume = "\n                                           Revenire la meniul principal?\n";
    while (ok) {
        print_default();
        set_color(GREY);
        select_(1, pos); printf(" Modificare stoc \n");
        set_color(GREY);
        select_(2, pos); printf(" Vizualizare stoc \n");
        set_color(GREY);
        select_(3, pos); printf(" Vizualizare comenzi \n");
        set_color(GREY);
        select_(4, pos); printf(" Vizualizare recenzii \n");
        set_color(GREY);
        select_(5, pos); printf(" Iesire \n");
        set_color(GREY);
        system("pause>nul");
        if (GetAsyncKeyState(VK_DOWN) && pos != 5) {
            pos++;
        }
        else if (GetAsyncKeyState(VK_UP) && pos != 1) {
            pos--;
        }
        else if (GetAsyncKeyState(VK_RETURN)) {
            switch (pos) {
            case 1:
                print_default();
                meniu_modificare();
                ok = revenire(nume);
                break;
            case 2:
                print_default();
                vizualizare_stoc();
                ok = revenire(nume);
                break;
            case 3:
                print_default();
                vizualizare_comenzi();
                ok = revenire(nume);
                break;
            case 4:
                print_default();
                vizualizare_recenzii();
                ok = revenire(nume);
                break;
            case 5:
                print_default();
                ok = !revenire("\n                                           Iesire din program?\n");
                break;
            default:
                print_default();
                std::cout << "nu trebuia sa ajungi aici";
                break;
            }
        }
    }
}

void adaugare_stoc() {
    bool check = true;
    int id, cantitate;
    double pret;
    std::string nume;
    set_color(WHITE);
    std::cout << "                                           ID Produs: ";
    set_color(COOLBLUE);
    std::cin >> id; std::cin.ignore();

    std::ifstream in;
    in.open(stoc);
    Produs y;
    while (in >> y) {
        if (y.get_id() == id) {
            print_default();
            set_color(WHITE);
            std::cout << "                                       Produsul cu ID: " << id << " exista deja ";
            Sleep(400);
            std::cout << ".";
            Sleep(400);
            std::cout << ".";
            Sleep(400);
            std::cout << ".";
            Sleep(900);
            return;
        }
    }

    set_color(WHITE);
    std::cout << "                                           Nume Produs: ";
    set_color(COOLBLUE);
    getline(std::cin, nume);

    set_color(WHITE);
    std::cout << "                                           Cantitate Produs: ";
    set_color(COOLBLUE);
    std::cin >> cantitate;

    set_color(WHITE);
    std::cout << "                                           Pret Produs: ";
    set_color(COOLBLUE);
    std::cin >> pret;

    std::ofstream out;
    out.open(stoc, std::ios_base::app);

    Produs x(id, nume, cantitate, pret);

    out << x << std::endl;
    out.close();

    print_default();
    set_color(WHITE);
    std::cout << "                                       Produsul a fost adaugat cu succes";
    Sleep(400);
    std::cout << ".";
    Sleep(400);
    std::cout << ".";
    Sleep(400);
    std::cout << ".";
    Sleep(900);

}

void vizualizare_stoc() {
    bool check = false;
    std::ifstream in;
    in.open(stoc);
    Produs x;
    while (in >> x) {
        check = true;
        x.afisare();
        Sleep(40);
    }
    if (check) {
        std::cout << "\n\n\n\n";
        system("pause");
    }
    else {
        print_default();
        set_color(WHITE);
        std::cout << "                                         Nu exista nici un produs in stoc";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(900);
    }
}

void stergere_stoc() {
    int id;
    int citite = 0, corecte = 0;
    set_color(WHITE);
    std::cout << "                                           ID Produs: ";
    set_color(COOLBLUE);
    std::cin >> id;

    std::vector<Produs>produse;

    std::ifstream in;
    in.open(stoc);
    Produs x;
    while (in >> x) {
        citite++;
        if (x.get_id() != id) {
            corecte++;
            produse.push_back(x);
        }
    }
    in.close();

    if (citite == corecte) {
        print_default();
        set_color(WHITE);
        std::cout << "                                         Nu exista produsul cu ID: " << id << " ";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(900);
    }
    else {
        std::ofstream out;
        out.open(stoc);

        for (auto& prod : produse) {
            out << prod << "\n";
        }

        out.close();

        print_default();
        set_color(WHITE);
        std::cout << "                                         Produsul cu ID: " << id << " a fost sters ";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(900);
    }
}

void modificare_id() {

    bool check = false;

    int id, id_nou;
    set_color(WHITE);
    std::cout << "                                           ID produs: ";
    set_color(COOLBLUE);
    std::cin >> id;

    std::vector<Produs>produse;

    std::ifstream in;
    in.open(stoc);
    Produs x;
    while (in >> x) {
        if (x.get_id() == id) {
            set_color(WHITE);
            std::cout << "                                           ID nou: ";
            set_color(COOLBLUE);
            std::cin >> id_nou;
            check = true;
            x.set_id(id_nou);
        }
        produse.push_back(x);
    }
    in.close();

    if (check) {
        std::ofstream out;
        out.open(stoc);

        for (auto& prod : produse) {
            out << prod << "\n";
        }

        out.close();

        print_modificat(id);
    }
    else {
        print_exista(id);
    }
}

void modificare_nume() {
    bool check = false;

    int id;
    std::string nume;
    set_color(WHITE);
    std::cout << "                                           ID produs: ";
    set_color(COOLBLUE);
    std::cin >> id;

    std::vector<Produs>produse;

    std::ifstream in;
    in.open(stoc);
    Produs x;
    while (in >> x) {
        if (x.get_id() == id) {
            set_color(WHITE);
            std::cout << "                                           Nume nou: ";
            set_color(COOLBLUE);
            std::cin.ignore();
            getline(std::cin, nume);
            check = true;
            x.set_nume(nume);
        }
        produse.push_back(x);
    }
    in.close();

    if (check) {
        std::ofstream out;
        out.open(stoc);

        for (auto& prod : produse) {
            out << prod << "\n";
        }

        out.close();

        print_modificat(id);
    }
    else {
        print_exista(id);
    }
}

void modificare_cantitate() {
    bool check = false;

    int id, cantitate;
    set_color(WHITE);
    std::cout << "                                           ID produs: ";
    set_color(COOLBLUE);
    std::cin >> id;

    std::vector<Produs>produse;

    std::ifstream in;
    in.open(stoc);
    Produs x;
    while (in >> x) {
        if (x.get_id() == id) {
            set_color(WHITE);
            std::cout << "                                           Cantitate noua: ";
            set_color(COOLBLUE);
            std::cin >> cantitate;
            check = true;
            x.set_cantitate(cantitate);
        }
        produse.push_back(x);
    }
    in.close();

    if (check) {
        std::ofstream out;
        out.open(stoc);

        for (auto& prod : produse) {
            out << prod << "\n";
        }

        out.close();

        print_modificat(id);
    }
    else {
        print_exista(id);
    }
}

void modificare_pret() {
    bool check = false;

    int id;
    double pret;
    set_color(WHITE);
    std::cout << "                                           ID produs: ";
    set_color(COOLBLUE);
    std::cin >> id;

    std::vector<Produs>produse;

    std::ifstream in;
    in.open(stoc);
    Produs x;
    while (in >> x) {
        if (x.get_id() == id) {
            set_color(WHITE);
            std::cout << "                                           Pret nou: ";
            set_color(COOLBLUE);
            std::cin >> pret;
            check = true;
            x.set_pret(pret);
        }
        produse.push_back(x);
    }
    in.close();

    if (check) {
        std::ofstream out;
        out.open(stoc);

        for (auto& prod : produse) {
            out << prod << "\n";
        }

        out.close();

        print_modificat(id);
    }
    else {
        print_exista(id);
    }
}

void print_modificat(int id) {
    print_default();
    set_color(WHITE);
    std::cout << "                                         Produsul cu ID: " << id << " a fost modificat ";
    Sleep(400);
    std::cout << ".";
    Sleep(400);
    std::cout << ".";
    Sleep(400);
    std::cout << ".";
    Sleep(900);
}

void print_exista(int id) {
    print_default();
    set_color(WHITE);
    std::cout << "                                         Nu exista produsul cu ID: " << id << " ";
    Sleep(400);
    std::cout << ".";
    Sleep(400);
    std::cout << ".";
    Sleep(400);
    std::cout << ".";
    Sleep(900);
}

void vizualizare_comenzi() {
    Data data;
    Produs produs;

    int numar_comenzi;
    std::ifstream in;
    in.open(comenzi);

    while (in >> data >> numar_comenzi) {
        std::vector<Produs>produse;
        for (int i = 0; i < numar_comenzi; i++) {
            in >> produs;
            produse.push_back(produs);
        }

        Cos_cumparaturi cos(numar_comenzi, produse, data);

        cos.afisare();
        std::cout << "\n";
    }
    system("pause");
}

void vizualizare_recenzii() {
    std::ifstream in;
    bool check = false;
    in.open(recenzii);
    Recenzie x;
    set_color(WHITE);
    while (in >> x) {
        std::cout << x<<"\n";
        check = true;
        in.ignore();
    }
    std::cout << std::endl;
    if (!check) {
        print_default();
        set_color(WHITE);
        std::cout << "                                         Nu exista nici o recenzie";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(900);
        return;
    }
    system("pause");
}