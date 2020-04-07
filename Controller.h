//
// Created by a on 4/5/2020.
//

#ifndef LAB4_CONTROLLER_H
#define LAB4_CONTROLLER_H
#include "Repository.h"
#include <string>

class Controller {
public:
    Repository repo;
public:
    // Default constructor
    Controller();

    // Constructor
    Controller(Repository repo);

    // Prints Liste mit Medikamente
    void printRepo() const;

    // Medikamente die die Menge kleiner als x haben
    void Menge_kleiner(double x) const;

    // Arata medicamentele care contine "substr" sortat dupa nume
    void strFind(std::string substr);

    // lista cu med sortate dupa pret
    void sort_by_price();
};


#endif //LAB4_CONTROLLER_H
