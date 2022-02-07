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


int lesson3()
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


int lesson4()
{
	// Syntax fehler
	//	Cout << "Erfolg!\n";
	//	cout << "Erfolg!\n;
	//	cout << "Erfolg" << !\n;
	//	cout << success << endl;
	//	string res = 7; vector<int> v(10); v[5] = res; cout << "Erfolg!\n";
	//	if( cond ) cout << "Erfolg!\n"; else cout << "Erfolg!\n";
	//	if( cond ) cout << "Erfolg!\n"; else cout << "Fehlschlag!\n";
	//	string s = "Affe"; boo c = "Narr" < s; if(c) cout << "Erfolg!\n";
	//	string s = "Affe"; if(s == "Narr")  cout < "Erfolg!\n";
	//	string s = "Affe"; if(s+"Narr") cout << "Erfolg!\n";
	//	if(true) then cout "Erfolg!\n"; else cout << "Fehlschlag!\n";	
	//	string<char> s= "Erfolg!\n"; for(int i = 0; i <= 10; i++) cout << s[i];
	//	std::cin << "Erfolg!\n";

	try 
	{	
		// ector<int> v(10); v[5] = 7; cout << "Erfolg!\n"; Richtig!
		// bool c = false; if( c ) cout << "Erfolg!\n"; else cout << "Fehlschlag!\n"; Richtig
		// string s = "Affe"; if(s == "Narr")  cout << "Erfolg!\n"; Richtig
		// vector<char> v(5); for (int i = 0; 0 < v.size(); i++); cout << "Erfolg!\n"; Falsch -> 0 < v.size()
		// vector<char> v(5); for (int i = 0; i <= v.size(); i++); cout << "Erfolg!\n"; Richtig
		// string s = "Erfolg!\n"; for (int i = 0; i < 6; i++) cout << s[i]; Falsch -> Erfolg!\n = 9 Zeichen, gibt aber nur bis zum 6ten zeichen aus
		// int x = 2000; char c = x; if(c==2000) cout << "Erfolg!\n"; Falsch int zu char 
		// string s = "Erfolg!\n"; for (int i = 0; i < 10; i++) cout << s[i]; Falsch out of Range!
		// vector<char> v(5); for (int i = 0; i <= v.size(); i++); cout << "Erfolg!\n"; Richtig
		// int i = 0; int j = 9; while(i<10) ++j; if(j<i) cout << "Erfolg!\n"; Falsch j++ und nicht i++
		// int x = 2; double d = 5 / (x-2); if(d==2*x+0.5) cout << "Erfolg!\n"; Falsch (x-2) = 0 
		// int i = 0; while(1<10) ++j; if(j<i) cout << "Erfolg!\n"; Falsch j = ?
		// int x = 4; double d = 5/(x-2); if(d=2*x+0.5) cout << "Erfolg!\n"; Richtig

		keep_window_open();
	}
	catch( exception& e )
	{
		std::cerr << "Hoppla: unbekannte Ausnahme!\n" << e.what();
		keep_window_open();
	}
	catch (...)
	{
		std::cerr << "Hoppla: unbekannte Ausnahme!\n";
		keep_window_open();
		return 2;
	}

	return 0;
}

void lesson5()
{
	double sum = 0;
	double high_temp = 0;
	double low_temp = 0;
	
	vector<double> value1 { -16.5, -23.2, -24.0, -25.7, -26.1, -18.6, -9.7, -2.4,
								7.5, 12.6, 23.8, 25.3, 28.0, 34.8, 36.7, 41.5, 
								40.3, 42.6, 39.7, 35.4, 12.6, 6.5, -3.7, -14.3 };

	vector<double> value2 { 76.5, 73.5, 71.0, 73.6, 70.1, 73.5, 70.1, 73.5, 77.6, 85.3, 
								 88.5, 91.7, 95.9, 99.2, 99.2, 98.2, 100.6, 106.3, 112.4, 
								 110.2, 103.6, 94.9, 91.7, 88.4, 85.2, 85.4, 87.7 }; 
	
    for (double x : value2)
    {
        if (high_temp == 0 && low_temp == 0) {
            high_temp = x;
            low_temp = x;
        }

        if (x > high_temp) high_temp = x;   // find high
        if (x < low_temp) low_temp = x;     // find low
        sum += x;
    }

	std::cout << "Hoechste Temperatur: " << high_temp << std::endl;
	std::cout << "Niedrigste Temperatur: " << low_temp << std::endl;
	std::cout << "Durschnittstemperatur:" << sum / value2.size() << std::endl;
}

double ctok(double c, int convert)
{
	if( c < -273.15) 
	{
		cout << "Achtung: Der absolute Nullpunkt wurde erreicht!"; 
		return 0; 
	}

	switch(convert){
	case 1:
		return c + 273.15;
		break;
	case 2:
		return c - 273.15;
		break;
	case 3:
		return (c * 9/5) + 32;
		break;
	default:
		cout << "Keine richtige eingabe";
	}

	return 0;
}

void lesson6()
{
	double c = 0;
	double d = 0;
	int e = 0;
	std::string output;

	cin >> d;
	cin >> e;

	double k = ctok(d, e);
	switch(e)
	{
	case 1:
		output = " K";
		break;
	case 2:
		output = " C";
		break;		
	case 3:
		output = " F";
		break;
	}
	
	
	cout << k << output << endl;
}


int main()
{
	lesson6();

}
