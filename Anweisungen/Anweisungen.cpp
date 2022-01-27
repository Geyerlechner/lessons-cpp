#include <iostream>

enum MONEY { EURO, DOLLAR };

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

double EuroToDollar(double money, enum MONEY type)
{
	
	if( type == EURO )
	{
		return money * 1.13;
	}
	else if( type== DOLLAR )
	{
		return money / 1.13;
	}
	 
	return 0;
}

int main()
{
	// InchToCM(2.5, "cm");
	
	std::cout << EuroToDollar(16.95, EURO);
}