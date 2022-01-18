#include <iostream>

void ifAnweisung()
{
	int a, b;

	a = 10;
	b = 12;

	std::cout << "Geben Sie bitte zwei ganze Zahlen ein: ";
	std::cin >> a >> b;

	if( a<b )
	{
		std::cout << "max(" << a << "," << b << ") ist " << b << "\n";
	}
	else
	{
		std::cout << "max(" << a << "," << b << ") ist " << a << "\n";
	}

}

void InchToCM(double input, const std::string to)
{

	if( to == "cm" )
	{
		std::cout << ( input * 2.54 ) << " cm";
	} else if( to == "inch" )
	{
		std::cout << ( input / 2.54 ) << " Inch";
	}
}

int main()
{
	InchToCM(2.5, "cm");
}