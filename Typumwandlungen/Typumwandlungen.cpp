#include <iostream>

int main()
{
    double d = 2.5;
    int i = 2;

    double  d2 = d/i; // d2 == 1.25
    int     i2 = d/i; // i2 == 1

    d2 = d/i; // d2 == 1.25
    i2 = d/i; // i2 == 1

    std::cout << "Ausgabe: " << d2 << std::endl 
              << i2 << std::endl
              << d2 << std::endl
              << i2 << std::endl;

    std::cout << std::endl;

    double dc;
    std::cout << "Eingabe: ";
    std::cin >> dc;
    double df = 9/5 * dc + 32;

    std::cout << "Wert 1: " << df;

    std::cout << std::endl;

    double dc;
    std::cout << "Eingabe 2: ";
    std::cin >> dc;
    double df = 9.0 / 5 * dc + 32; //Besser

    std::cout << "Wert 2: " << df;


}
