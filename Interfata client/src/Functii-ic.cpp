#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Functii-ic.h"
#include "Headers.h"

void print_default() {
    system("cls");
    set_color(GREY);
    std::cout << "\n\n\n                                     -------------";
    set_color(BLUE);
    std::cout << "Interfata client";
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

Cos_cumparaturi cart;

void meniu() {

    bool ok = TRUE;
    int pos = 1;
    std::string nume = "\n                                           Revenire la meniul principal?\n";
    while (ok) {
        print_default();
        set_color(GREY);
        select_(1, pos); printf(" Vizualizare stoc \n");
        set_color(GREY);
        select_(2, pos); printf(" Vizualizare cos \n");
        set_color(GREY);
        select_(3, pos); printf(" Adaugare produs in cos \n");
        set_color(GREY);
        select_(4, pos); printf(" Modificare produs \n");
        set_color(GREY);
        select_(5, pos); printf(" Creare recenzie \n");
        set_color(GREY);
        select_(6, pos); printf(" Finalizare comanda \n");
        set_color(GREY);
        select_(7, pos); printf(" Iesire \n");
        set_color(GREY);
        system("pause>nul");
        if (GetAsyncKeyState(VK_DOWN) && pos != 7) {
            pos++;
        }
        else if (GetAsyncKeyState(VK_UP) && pos != 1) {
            pos--;
        }
        else if (GetAsyncKeyState(VK_RETURN)) {
            switch (pos) {
            case 1:
                print_default();
                vizualizare_stoc1();
                ok = revenire(nume);
                break;
            case 2:
                print_default();
                vizualizare_cos();
                ok = revenire(nume);
                break;
            case 3:
                print_default();
                adaugare_produs_cos();
                ok = revenire(nume);
                break;
            case 4:
                print_default();
                modificare_produs();
                ok = revenire(nume);
                break;
            case 5:
                print_default();
                creare_recenzie();
                ok = revenire(nume);
                break;
            case 6:
                print_default();
                finalizare_comanda();
                ok = revenire(nume);
                break;
            case 7:
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

void vizualizare_stoc1() {
    bool check = false;
    std::ifstream in;
    in.open(stoc);
    Produs x;
    while (in >> x) {
        check = true;
        x.afisare();
        Sleep(40);
    }
    in.close();
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

void adaugare_produs_cos() {
    bool check = false;
    std::ifstream in;
    in.open(stoc);
    Produs x;
    std::vector<Produs> lista;
    while (in >> x) {
        check = true;
        x.afisare();
        lista.push_back(x);
        Sleep(40);
    }
    in.close();
    if (check) {
        std::cout << "\n\n\n\n";
        int idp, cantitate;
        std::cout << "Introduceti id-ul produsului dorit: ";
        set_color(COOLBLUE);
        std::cin >> idp;
        for (auto& prod : lista) {
            if (idp == prod.get_id()) {
                while (TRUE) {
                    set_color(WHITE);
                    std::cout << "Introduceti cantitatea produsului dorit: ";
                    set_color(COOLBLUE);
                    std::cin >> cantitate;
                    if (cantitate <= prod.get_cantitate()) {
                        Produs x = prod;
                        x.set_cantitate(cantitate);
                        cart.append(x);
                        break;
                    }
                }
            }
        }
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

void modificare_produs() {
    bool check = false;
    for (auto& produs : cart.get_lista()) {
        check = true;
        produs.afisare();
        Sleep(40);
    }
    if (check) {
        std::cout << "\n\n\n\n";
        int idp, cantitate, cantitate_originala=0;
        set_color(WHITE);
        std::cout << "Introduceti id-ul produsului: ";
        set_color(COOLBLUE);
        std::cin >> idp;
        int index = 0;
        for (auto& produs : cart.get_lista()) {
            index++;
            if (idp == produs.get_id()) {
                std::ifstream in;
                in.open(stoc);
                Produs x;
                while (in >> x) {
                    if (idp == x.get_id()) {
                        cantitate_originala = x.get_cantitate();
                        break;
                    }
                }     
                while (TRUE) {
                    set_color(WHITE);
                    std::cout << "Introduceti cantitatea noua a produsului: ";
                    set_color(COOLBLUE);
                    std::cin >> cantitate;
                    if (cantitate == 0) {
                        cart.stergere_produs(produs);
                        break;
                    }
                    if (cantitate <= cantitate_originala) {
                        cart.set_cantitate(produs, cantitate);
                        break;
                    }
                }
            }
        }
    }
    else {
        print_default();
        set_color(WHITE);
        std::cout << "                                         Nu exista nici un produs in cos";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(900);
    }
}
void vizualizare_cos() {
    bool check = false;
    for (auto& produs : cart.get_lista()) {
        check = true;
        produs.afisare();
        Sleep(40);
    }
    if (check) {
        std::cout << "\n\n\n\n";
        system("pause");
    }
    else {
        print_default();
        set_color(WHITE);
        std::cout << "                                         Nu exista nici un produs in cos";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(400);
        std::cout << ".";
        Sleep(900);
    }
}
void creare_recenzie() {
    std::ofstream out;
    out.open(recenzii, std::ios_base::app);
    std::string text;
    set_color(WHITE);
    std::cout << "Scrieti o recenzie:";
    set_color(COOLBLUE);
    getline(std::cin, text);
    Recenzie x = { text };
    out << x << std::endl;
    out.close();

}
void finalizare_comanda() {
    double pret = 0, aux1, aux2;
    bool check = false;
    for (auto& produs : cart.get_lista()) {
        check = true;
        aux1 = produs.get_cantitate();
        aux2 = produs.get_pret();
        pret += aux1 * aux2;
    }
    if(!check) {
    print_default();
    set_color(WHITE);
    std::cout << "                                         Nu exista nici un produs in cos\n";
    std::cout << "                                         Comanda nu poate fi finalizata";
    Sleep(400);
    std::cout << ".";
    Sleep(400);
    std::cout << ".";
    Sleep(400);
    std::cout << ".";
    Sleep(900);
    return;
    }
    std::ofstream out;
    out.open(comenzi, std::ios_base::app);
    out << cart;
    out.close();
    std::ifstream in1;
    std::ofstream out1;
    in1.open(stoc);
    out1.open(stoc_aux);
    Produs x;
    while (in1 >> x) {
        for (auto& produse : cart.get_lista())
            if (x.get_id() == produse.get_id())
                x.set_cantitate(x.get_cantitate() - produse.get_cantitate());
        out1 << x << std::endl;
    }
    out1.close();
    in1.close();
    std::ifstream in2;
    std::ofstream out2;
    in2.open(stoc_aux);
    out2.open(stoc);
    Produs y;
    while (in2 >> y) {
        out2 << y << std::endl;
    }
    out2.close();
    in2.close();
    set_color(WHITE);
    std::cout << "Pretul total este de: ";
    set_color(COOLBLUE);
    std::cout << pret;
    set_color(WHITE);
    std::cout << " lei\n";
    system("pause");
}