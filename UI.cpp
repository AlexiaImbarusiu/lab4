//
// Created by a on 4/5/2020.
//

#include "UI.h"
#include <iostream>
using namespace std;

ApothekeUI::ApothekeUI(Controller _ctrl) : ctrl(_ctrl){
}


void Infos() {


    cout << "0. Exit\n";
    cout << "1. Adaugare medicament\n";
    cout << "2. sterge medicament\n";
    cout << "3. Editeaza medicament \n";
    cout << "4. Cauta medicament cu un string dat\n";
    cout << "5. Cauta medicament cu cantitatea mai mica decat valoarea introdusa\n";
    cout << "6. sorteaza med dupa pret\n";
    cout << "7. UNDO \n";
    cout << "8. REDO \n";
}


void ApothekeUI::UI() {
    // Es gibt 9 mogliche Operationen, also 9 if statements, in jeder if statement wird eine Operation gemacht

    Infos();
    int input;
    string name, new_name, zeichen;
    double konzentration, menge, preis, new_konzentration, new_menge, new_preis;
    cout << "\nInput: "; cin >> input;
    while (input != 0) {
        if (input == 1) {
            cout << "Name: "; cin >> name;
            cout << "Konzentration: "; cin >> konzentration;
            cout << "Menge: "; cin >> menge;
            cout << "Preis: "; cin >> preis;
            Medikament med = Medikament(name, konzentration, menge, preis);
            ctrl.repo.add_medikament(med);
        }
        else if (input == 2) {
            cout << "Name: "; cin >> name;
            cout << "Konzentration: "; cin >> konzentration;
            cout << "Menge: "; cin >> menge;
            cout << "Preis: "; cin >> preis;
            Medikament med = Medikament(name, konzentration, menge, preis);
            ctrl.repo.delete_medikament(med);
        }
        else if (input == 3) {
            cout << "Name: "; cin >> name;
            cout << "Konzentration: "; cin >> konzentration;
            cout << "Menge: "; cin >> menge;
            cout << "Preis: "; cin >> preis;
            cout << "neuer Name: "; cin >> new_name;
            cout << "neue Konzentration: "; cin >> new_konzentration;
            cout << "neue Menge: "; cin >> new_menge;
            cout << "neues Preis: "; cin >> new_preis;
            Medikament med = Medikament(name, konzentration, menge, preis);
            Medikament med2 = Medikament(new_name, new_konzentration, new_menge, new_preis);
            ctrl.repo.edit_medikament(med, med2);
        }
        else if (input == 4) {
            cout << "\nZeichen: "; cin >> zeichen;
            ctrl.strFind(zeichen);
        }
        else if (input == 5) {
            cout << "Geben sie den Wert von X:\n";
            double X;
            cout << "X: "; cin >> X;
            ctrl.Menge_kleiner(X);
        }
        else if (input == 6) {
            ctrl.sort_by_price();
        }
        else if (input == 7) {
            ctrl.repo.undo();
        }
        else if (input == 8) {
            ctrl.repo.redo();
        }
        else if (input == 0)
            exit(0);
        else cout << "wrong input\n";

        Infos();
        cout << "\nInput: "; cin >> input;
    }
}