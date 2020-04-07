//
// Created by a on 4/5/2020.
//

#ifndef LAB4_MEDIKAMENT_H
#define LAB4_MEDIKAMENT_H
#pragma once
#include <string>

using namespace std;


class Medikament {
private:
    string name;
    double konzentration;
    double menge;
    double preis;

public:
    // Constructor
    Medikament(string nume, double concentr, double cant, double pret);

    // returneaza numele medicamentului
    string getName() const;

    // schimba numele medicamentului
    void setName(string nume);

    // returneaza concentratia
    double getKonzentration() const;

    // modifica concentratia
    void setKonzentration(double concentr);

    // returneaza cantitatea
    double getMenge() const;

    // seteaza cantitatea
    void setMenge(double cant);

    // returneaza pretul
    double getPreis() const;

    // seteaza pret
    void setPreis(double pret);

    // print
    string toString() const;

    //Comparsion Operators
   friend bool operator == (const Medikament& m1, const Medikament& m2);
   friend bool operator != (const Medikament& m1, const Medikament& m2);
};

#endif //LAB4_MEDIKAMENT_H
