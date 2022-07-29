#include <iostream>
#include "Person.h"
#include "Client.h"
void Clear() {
    std::cout << "\033[2J\033[1;1H";
}
int Person::ID = 1;

int main()
{   
    Client c1("Abdelfattah Mohamed", "123", 1600);
    Client c2("Mahmoud Mohamed", "123", 1700);
    c2.transferTo(50, c1);
    c1.Display();
    c2.Display();
}

