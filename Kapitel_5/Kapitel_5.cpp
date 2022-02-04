#include <iostream>
#include "std_lib_facilities.h"

int area(int length, int width)
{
	return length*width;
}

int framed_area(int x, int y) // berechnet die Fläche innerhalb eines Rahmens
{
	const int frame_width = 2;
	if( x-frame_width <= 0 || y-frame_width <= 0 )
		error("area()-Argument in framed_area() ist nicht positiv");
		
	return area(x-frame_width, y-frame_width);
}

void lesson_1()
{

	//Typefehler
	// int x0 = arena(7); //Fehler: nicht deklariete Funktion
	// int x1 = area(7); // Fehler: falsche Anzahl an Argumenten
	// int x2 = area("seven", 2); // Fehler: erstes Argument hat den falschen Typ
	int x = 2;
	int y = 3;
	int z = 2;

	if( x <= 0 || y <= 0 ) error("area()-Argument ist nicht positiv");
	int area1 = area( x, y );
	
	if( z <= 2 )
		error("area()-Argument ist nicht positiv");
	int area2 = framed_area( 1, z );
	
	if( y <= 2 || z <= 2 )
		error("area()-Argument ist nicht positiv");
	int area3 = framed_area( y, z );

}

void lesson_2()
{

	int x = 0;
	int y = 0;
		
	std::cout << "Geben Sie 2 werte ein! X & Y  \nGeben Sie einen wert fuer x ein: " ;
	std::cin >> x;
	std::cout << "Geben Sie einen wert fuer y ein: ";
	std::cin >> y;

	if( x == 0 ){
		std::cout << "Es wurde kein wert fuer x eingeben!";
	}else if ( y == 0 )
	{
		std::cout << "Es wurde kein wert fuer y eingeben!";
	}

}

int main()
{





}
