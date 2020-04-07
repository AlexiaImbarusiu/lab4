#include <iostream>
#include "UI.h"
#include "Test.h"
int main() {
    std::cout << "Testing!!\n\n";
    Test t;
    t.allTests();
    std::cout << "Tests Over!!\n\n";
    Repository repo;
    Controller ctrl = Controller(repo);
    ApothekeUI au = ApothekeUI(ctrl);
    au.UI();
}
