#include <iostream>
#include "std_lib_facilities.h"
#include <vector>
class Bad_area {}; //Typ, der speziell für das Melden von Fehlern aus area() definiert wurde

int area(int length, int width)
{
	if(length <= 0 || width <= 0) throw Bad_area();

	return length * width;
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


void tryCatch()
{
	try {
	
		int x = -1;
		int y = 2;
		int z = 4;

		int area1 = area( x, y );
		int area2 = framed_area( 1, z );
		int area3 = framed_area( y, z );
		double ratio = area1/area3;

	}
	catch(Bad_area){
		std::cout << "Hoppla! Ungueltige Argumente fuer area()\n";
	}

}

//class out_of_range {};
//
//	vector<int> v; // ein Vektor für ganze Zahlen
//	int i;
//
//	while (cin>>i) v.push_back(i);		// lies Werte ein
//	for (int i = 0; i <= v.size(); i++) {	// gibt Werte aus
//		std::cout << "v[" << i <<"] == " << v[i] << std::endl; 
//	}
//	catch(out_of_range)
//	{
//		cerr << "Hoppla! Bereichsfehler\n";
//		return 1;
//	}catch(...)
//	{
//		cerr << "Ausnahme: irgendetwas ist schiefgelaufen\n";
//		return 2;
//	}
	

void error(string s1, string s2)
{
	throw runtime_error(s1 + s2);
}

//try {
//	return 0;
//}
//catch( runtime_error& e ){
//	cerr << "Laufzeitfehler:" << e.what() << "\n";
//	keep_window_open();
//	return 1;
//}
//catch(...)
//{
//	cerr << "Hoppla! unbekannte Ausnahne!\n";
//	keep_window_open();
//	return 2; // 2 steht für "Fehlgeschlagen"
//}

int main()
{
	try {
		int x1  = narrow_cast<int>(2.9); // wirft eine Ausnahme
		int x2  = narrow_cast<int>(2.0); // O.K.
		char c1 = narrow_cast<int>(1066); // wirft eine Ausnahme
		char c2 = narrow_cast<int>(85); // O.K.
		return 0;
	}
	catch( runtime_error& e ){
		cerr << "laufzeitfehler:" << e.what() << "\n";
		keep_window_open();
		return 1;
	}
	catch(...)
	{
		cerr << "hoppla! unbekannte ausnahne!\n";
		keep_window_open();
		return 2; // 2 steht für "fehlgeschlagen"
	}
}
