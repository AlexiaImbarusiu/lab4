//
// Created by a on 4/5/2020.
//

#include "Test.h"
#include "Controller.h"
#include <cassert>



void Test::testAdd() const {
    Repository  r;
    r.add_medikament(m1);
    r.add_medikament(m2);
    r.add_medikament(m3);
    r.add_medikament(m4);
    r.add_medikament(m5);
    r.add_medikament(m6);
    r.add_medikament(m7);
    r.add_medikament(m8);
    r.add_medikament(m9);
    r.add_medikament(m10);
    assert(r.getMedikament_byIndex(0).getMenge() == 11);
    assert(r.getMedikament_byIndex(6).getMenge() == 12);
}


void Test::testDelete() const{
    Repository r;
    r.add_medikament(m1);
    r.add_medikament(m2);
    r.add_medikament(m2);
    assert(r.getSize() == 2);
    r.delete_medikament(m1);
    assert(r.getSize() == 1);
    assert(r.getMedikament_byIndex(0).getMenge() == 6);
    r.delete_medikament(m2);
    assert(r.getMedikament_byIndex(0).getMenge() == 3);
}

void Test::testEdit()  const{
    Repository r;
    Medikament med2 = Medikament("PROPOLIS", 20, 5, 14.02);
    r.add_medikament(m1);
    assert(r.getMedikament_byIndex(0).getName() == "SORTIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 1);
    assert(r.getMedikament_byIndex(0).getPreis() == 16.66);
    r.edit_medikament(m1, med2);
    assert(r.getMedikament_byIndex(0).getName() == "PROPOLIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 5);
    assert(r.getMedikament_byIndex(0).getPreis() == 14.02);

}

void Test::testUndo() const {
    Repository r;
    Medikament med2 = Medikament("PROPOLIS", 20, 5, 14.02);
    r.add_medikament(m1);
    assert(r.getSize() == 1);
    r.undo();
    assert(r.getSize() == 0);

    r.add_medikament(m1);
    r.delete_medikament(m1);
    assert(r.getSize() == 0);
    r.undo();
    assert(r.getSize() == 1);

    r.edit_medikament(m1, med2);
    assert(r.getMedikament_byIndex(0).getName() == "PROPOLIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 5);
    assert(r.getMedikament_byIndex(0).getPreis() == 14.02);
    r.undo();
    assert(r.getMedikament_byIndex(0).getName() == "SORTIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 1);
    assert(r.getMedikament_byIndex(0).getPreis() == 16.66);
}

void Test:: testRedo() const {
    Repository r;
    Medikament med2 = Medikament("PROPOLIS", 20, 5, 14.02);
    r.add_medikament(m1);
    assert(r.getSize() == 1);
    r.undo();
    assert(r.getSize() == 0);
    r.redo();
    assert(r.getSize() == 1);

    r.delete_medikament(m1);
    assert(r.getSize() == 0);
    r.undo();
    assert(r.getSize() == 1);
    r.redo();
    assert(r.getSize() == 0);

    r.add_medikament(m1);
    r.edit_medikament(m1, med2);
    assert(r.getMedikament_byIndex(0).getName() == "PROPOLIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 5);
    assert(r.getMedikament_byIndex(0).getPreis() == 14.02);
    r.undo();
    assert(r.getMedikament_byIndex(0).getName() == "SORTIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 1);
    assert(r.getMedikament_byIndex(0).getPreis() == 16.66);
    r.redo();
    assert(r.getMedikament_byIndex(0).getName() == "PROPOLIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 5);
    assert(r.getMedikament_byIndex(0).getPreis() == 14.02);
}

void Test::testKnapp() const {
    Repository  r;
    r.add_medikament(m1);
    r.add_medikament(m2);
    r.add_medikament(m3);
    r.add_medikament(m4);
    r.add_medikament(m5);
    r.add_medikament(m6);
    r.add_medikament(m7);
    r.add_medikament(m8);
    r.add_medikament(m9);
    r.add_medikament(m10);

    Controller c = Controller(r);
    c.Menge_kleiner(7);
}


void Test::testStrFind() const {
    Repository  r;
    r.add_medikament(m1);
    r.add_medikament(m2);
    r.add_medikament(m3);
    r.add_medikament(m4);
    r.add_medikament(m5);
    r.add_medikament(m6);
    r.add_medikament(m7);
    r.add_medikament(m8);
    r.add_medikament(m9);
    r.add_medikament(m10);

    Controller c = Controller(r);
    c.strFind("");
    c.strFind("ORTI");
}


void Test::testGroupPrice() const {
    Repository  r;
    r.add_medikament(m1);
    r.add_medikament(m2);
    r.add_medikament(m3);
    r.add_medikament(m4);
    r.add_medikament(m5);
    r.add_medikament(m6);
    r.add_medikament(m7);
    r.add_medikament(m8);
    r.add_medikament(m9);
    r.add_medikament(m10);

    Controller c = Controller(r);
    c.sort_by_price();
}


void Test::allTests() const {
    Test t;
    t.testAdd();
    t.testDelete();
    t.testEdit();
    t.testUndo();
    t.testRedo();
    t.testKnapp();
    t.testStrFind();
    t.testGroupPrice();
}