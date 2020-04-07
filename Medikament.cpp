//
// Created by a on 4/5/2020.
//

#include "Medikament.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


Medikament::Medikament(string nume, double concentr, double cant, double pret) {
    name = nume;
    konzentration = concentr;
    menge = cant;
    preis = pret;
}


string Medikament::getName() const {
    return this->name;
}


void Medikament::setName(string nume) {
    this->name = nume;
}


double Medikament::getKonzentration() const {
    return this->konzentration;
}


void Medikament::setKonzentration(double concentr) {
    this->konzentration = concentr;
}


double Medikament::getMenge() const {
    return this->menge;
}


void Medikament::setMenge(double cant) {
    this->menge = cant;
}


double Medikament::getPreis() const {
    return this->preis;
}


void Medikament::setPreis(double pret) {
    this->preis = pret;
}


string Medikament::toString() const {
    stringstream out;
    out << "Name: " << this->getName()<< endl << "\tKonzentration: " << this->getKonzentration() << endl << "\tMenge: " << this->getMenge() << endl << "\tPreis: " << this->getPreis() << endl << endl;
    return out.str();
}


bool operator == (const Medikament& m1, const Medikament& m2) {
    return (m1.getName() == m2.getName() && m1.getKonzentration() == m2.getKonzentration());
}

bool operator != (const Medikament& m1, const Medikament& m2) {
    return !(m1 == m2);
}