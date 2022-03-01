#include <iostream>
#include <math.h>
#include <vector>
#include <string>

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
void shiftright (int myarray[], int size)
{
  for (int i=0; i<size; i++)
  {
    myarray[i] ;
  }
}

template <typename t> void move(std::vector<t>& v, size_t oldIndex, size_t newIndex)
{
    if (oldIndex > newIndex)
        std::rotate(v.rend() - oldIndex - 1, v.rend() - oldIndex, v.rend() - newIndex);
    else        
        std::rotate(v.begin() + oldIndex, v.begin() + oldIndex + 1, v.begin() + newIndex + 1);
}

int main()
{

  std::cout << "Please, enter a number or a word: ";
  char c = std::cin.get();

  if ( (c >= '0') && (c <= '9') )
  {
    int n;
    std::cin.putback (c);
    std::cin >> n;
    std::cout << "You entered a number: " << n << '\n';
  }
  else
  {
    std::string str;
    std::cin.putback (c);
    std::getline (std::cin,str);
    std::cout << "You entered a word: " << str << '\n';
  }

  system("pause");


    //std::vector<int> v{ 1, 2, 3, 4, 5 };  

    //move(v, 2, v.size()-1);
    //move(v, 1, v.size()-1);

    //for ( auto e : v )
    //{
    //    std::cout << e << " ";
    //}

}