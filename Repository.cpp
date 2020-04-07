//
// Created by a on 4/5/2020.
//

#include "Repository.h"
#include <algorithm>
#include "Medikament.h"
using namespace std;

void Repository::add_medikament(Medikament med)
{
    lastOperation = "add";
    lastMedicament = med;
    bool gas = false;
    for (std::size_t i = 0; i < medikamente.size(); ++i)
        if (medikamente[i] == med) {
            medikamente[i].setMenge(medikamente[i].getMenge() + med.getMenge());
            gas = true;
            break;
        }
    if (gas == false)  // Wenn dieses Medikament nicht existiert, wird am Ende des Vektors eingefugt
        medikamente.push_back(med);
}

void Repository::delete_medikament(Medikament med) {
    lastOperation = "delete";
    lastMedicament = med;
    for(int i = 0; i < medikamente.size(); ++i) {
        if (medikamente[i] == med && med.getMenge() == 1 || medikamente[i].getMenge() - med.getMenge() == 0) {
            medikamente.erase(medikamente.begin()+i);       //If the medicine exists and has only 1 ammount, then it erases the medicine from the vector completely
            break;
        }
        else{        //if the medicine has more than 1 amount, then it removes by amount
            medikamente[i].setMenge(medikamente[i].getMenge() - med.getMenge());
            break;
        }
    }
}

void Repository::edit_medikament(Medikament _medikament, Medikament newMedikament) {
    lastOperation = "edit";
    lastMedicament = _medikament;
    newMedicament = newMedikament;
    for (std::size_t i = 0; i < medikamente.size(); ++i)
        if (medikamente[i] == _medikament) {
            medikamente[i].setName(newMedikament.getName());
            medikamente[i].setKonzentration(newMedikament.getKonzentration());
            medikamente[i].setMenge(newMedikament.getMenge());
            medikamente[i].setPreis(newMedikament.getPreis());
        }
}

void Repository::undo(){
    if(lastOperation == "add"){     // if the last operation was "add", it deteles the added medicine
        delete_medikament(lastMedicament);
        lastOperation = "";
        lastUndo = "delete";
    }
    if(lastOperation == "delete") {     // if the last operation was "delete", it adds the deleted medicine
        add_medikament(lastMedicament);
        lastOperation = "";
        lastUndo = "add";
    }
    if(lastOperation == "edit"){        //if the last operation was "edit", it edits the medicine to the one before there was any changes
        edit_medikament(newMedicament,lastMedicament );
        lastOperation = "";
        lastUndo = "edit";
    }
}

void Repository::redo(){
    if(lastUndo == "add"){      //if the undo operation was "add", it deletes the added medicine
        delete_medikament(lastMedicament);
        lastOperation = "";
        lastUndo = "";
    }
    if(lastUndo == "delete") {      //if the undo operation was "delete", it adds the deleted medicine
        add_medikament(lastMedicament);
        lastOperation = "";
        lastUndo = "";
    }
    if(lastUndo == "edit"){     //if the undo operation was "edit", it edits the medicine to the one before the undo operation
        edit_medikament(newMedicament,lastMedicament );
        lastOperation = "";
        lastUndo = "";
    }
}


std::vector<Medikament> Repository::getMedikamente() const {
    return this->medikamente;
}


Medikament Repository::getMedikament_byIndex(int index) const {
    return this->medikamente[index];
}


double Repository::getSize() const {
    return this->medikamente.size();
}


bool compareName(Medikament m1, Medikament m2) {
    return m1.getName() < m2.getName();
}


void Repository::sortByName() {
    sort(medikamente.begin(), medikamente.end(), compareName);
}


bool comparePreis(Medikament m1, Medikament m2) {
    return m1.getPreis() < m2.getPreis();
}


void Repository::sortByPrice() {
    sort(medikamente.begin(), medikamente.end(), comparePreis);
}