#include <iostream>
#include <math.h>

//Seite: 94 -  98
 
//Seite: 101
void lesson_1()
{
    std::cout << "Bitte geben Sie Ihrem Vornamen ein (gefolgt von Enter)" << std::endl;
    
    std::string first_name;
    int alter; 

    std::cout << "Name: "; 
    std::cin >> first_name;

    std::cout << "Alter: ";
    std::cin >> alter;

    std::cout << "Hallo " 
              << first_name   
              << " Alter: " 
              <<  alter     << std::endl;
}
//Seite: 101
void lesson_2()
{
    std::cout << "Geben Sie einen Gleitkommawert ein: ";
    double n;
    std::cin >> n;

    std::cout << "Ausgabe: " << sqrt(n);
}
//Seite: 101
void lesson_3()
{
    std::cout << "Bitte geben Sie Ihren Vor- und Nachnamen ein " << std::endl << "Name: "; 
    std::string first;
    std::string last;
    std::cin >> first >> last;

    std::cout << "Hallo " << first << " " << last;
}

int main()
{
   

}