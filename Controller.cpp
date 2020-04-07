//
// Created by a on 4/5/2020.
//

#include "Controller.h"
#include <string>
#include <iostream>

using namespace std;


Controller::Controller() {
    Repository repo;
    this->repo = repo;
}


Controller::Controller(Repository repo) : repo(repo) {

}


void Controller::printRepo() const {
    for (std::size_t i = 0; i < repo.getSize(); ++i)
        cout << repo.getMedikament_byIndex(i).toString();
    cout << endl << endl;
}


void Controller::Menge_kleiner(double x) const {
    cout << "\nDie Medikamente, die die Menge kleiner als " << x << " haben, sind:\n";
    for (std::size_t i = 0; i < repo.getSize(); ++i)
        if (repo.getMedikament_byIndex(i).getMenge() < x)   // Wenn die Menge kleiner als x ist, dann wird dieses Medikament eingezeigt
            cout << repo.getMedikament_byIndex(i).toString();
    cout << endl << endl;
}


void Controller::strFind(std::string substr) {
    if (substr == "") {
        cout << "\nSubstring war leer, eine Liste mit alle Medikamente wird angezeigt:\n";
        repo.sortByName();
        this->printRepo();
    }
    else {
        cout << "\nEs werden die Medikamente angezeigt, die '" << substr << "' enthalten:\n";
        for (std::size_t i = 0; i < repo.getSize(); ++i)
            if (repo.getMedikament_byIndex(i).getName().find(substr) != string::npos)
                cout << repo.getMedikament_byIndex(i).toString();
        cout << endl << endl;
    }
}


void Controller::sort_by_price() {
    cout << "\nEs werden die Medikamente, nach Preis gruppiert, angezeigt:\n";
    repo.sortByPrice();
    this->printRepo();
}