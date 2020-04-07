//
// Created by a on 4/5/2020.
//

#ifndef LAB4_UI_H
#define LAB4_UI_H
#include "Controller.h"

class ApothekeUI {
private:
    Controller ctrl;
public:
    // Constructor
    ApothekeUI(Controller ctrl);

    // Functie cu user input
    void UI();
};


#endif //LAB4_UI_H
