#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

#include "uebungen.h"

double KilometerToMeilen(double meilen)
{
	return meilen * 1.609;
}

void lessons1(int val1, int val2)
{

	std::string ist = ( val1 > val2 )	?	"Eingabe 1 ist groesser Wert: " + std::to_string(val1) 
										:	"Eingabe 2 ist groesser Wert: " + std::to_string(val2);

	std::cout << "Ausgabe: " << ist << std::endl;
	std::cout << "Ouotient: " << std::abs( val1 / val2 ) << std::endl;
	std::cout << "Differenz: " << std::abs( val1 - val2 ) << std::endl;
}

void lessons2(int val1, int val2, int val3)
{
	int a[] = { val1, val2, val3 };
	std::ranges::sort( a );

	for ( auto e : a )
		std::cout << e << " ";

}

void lessons3(std::string val1, std::string val2, std::string val3)
{
	std::vector< std::string > arr { val1, val2, val3 };

	std::sort( arr.begin(), arr.end() );

	for ( auto e : arr )
		std::cout << e << " ";
}
void lessons4(int zahl)
{
	if ( zahl % 2 == 0 )
		std::cout << "Der Wert " << zahl << " ist eine gerade Zahl";
	else
		std::cout << "Der Wert " << zahl << " ist eine ungerade Zahl";
	
}
void lessons5(int zahl)
{
	auto print = [](std::string message) { std::cout << message << "\n"; };
	
	switch(zahl)
	{
	case 0:
		print("null");
		break;
	case 1:
		print("eins");
		break;
	case 2:
		print("zwei");
		break;
	case 3:
		print("drei");
		break;
	case 4:
		print("vier");
		break;
	case 5:
		print("fünf");
		break;
	case 6:
		print("sechs");
		break;
	case 7:
		print("sieben");
		break;
	case 8:
		print("acht");
		break;
	}
}

int test()
{
	return 10;
}

void start_117()
{
	auto i = test();
	auto test = [ &i ]( int b ) -> int
	{ 
		return i + b;
	};
	
	std::cout << test(10);

	//lessons3( "Steinbeck", "Fitzgerald", "Hemingway" );
	//lessons4( 100 );
	//lessons5( 8 );
	//lessons2( 10, 11, 6 );
	//std::cout << KilometerToMeilen(3);
	//int a;
	//int b;
	//std::cin >> a;
	//std::cin >> b;
	//lessons1(a, b);

}