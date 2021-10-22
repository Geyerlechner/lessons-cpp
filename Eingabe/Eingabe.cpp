#include <iostream>

//Seite: 94 -  98

int main()
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