#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <map>

bool searchBlockList(std::vector<std::string> bocklist, std::string word)
{
	// https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
	std::transform(word.begin(), word.end(), word.begin(),
    [](unsigned char c){ return std::tolower(c); });

	for( auto searchString : bocklist )
	{
		if( searchString == word ) return true;
	}
	return false;
}

void vector_lesson1()
{
	std::vector<std::string> words;

	std::string temp;

	std::vector<std::string> blockList = { "fuck", "arsch", "dumm" };

	while(std::cin>>temp)
	{
		if(temp == "stop")
			break;

		searchBlockList(blockList, temp) ? temp = "XXX" : temp = temp;
		words.push_back(temp);

	}

	std::cout << "Anzahl Woerter: " << words.size() << std::endl;
	std::sort(words.begin(), words.end());

	for (auto value : words)
	{
		std::cout << value << " ";
	}
}

void vector_lesson2()
{

	char input;
	int a = 0;
	int b = 0;

	std::cout << "1 zum Starten oder stop zum Beenden!\nEingabe: ";
	while( std::cin>>input )
	{
		if( input == 'stop' ) break;

		std::cout << "Geben Sie die erste Zahl ein: ";
		std::cin >> a;
		std::cout << "Geben Sie die zweite Zahl ein: ";
		std::cin >> b;

		std::cout << "Ausgabe: " << "Zahl 1: " << a << " Zahl 2: " << b;

	}

}

void vector_lesson3()
{
	double number1 = 0;
	double number2 = 0;

	std::cout << "Geben Sie eine Zahl ein: ";
	while( std::cin >> number1 )
	{
		if( number1 == 000 )
			break;

		std::cout << "Geben Sie eine 2 Zahl ein: ";
		std::cin >> number2;

		std::cout << "Ausgabe: ";

		if( number1 > number2 )
		{
			std::cout << "Die erste eingabe ist groesser als die Zweite " << number1 << std::endl;
		}else if ( number1 == number2 )
		{
			std::cout << "Die beiden Zahlen sind gleich" << std::endl;
		} else
		{
			std::cout << "Die zweite eingabe ist groesser als die erste " << number2 << std::endl;
		}

		std::cout << "Eingabe: ";
	}
}

void vector_lesson4()
{
	int units;
	std::vector<double> values;

	std::cout << "Was wollen Sie in cm umrechnen? \n------------------------------------\n";
	std::cout << "m  = 0 \nin = 1 \nft = 2 \nPrint & Exit = 3\n------------------------------------\nEingabe: ";

	while( std::cin >> units )
	{
		double InputValue = 0;

		auto unity = [&](int value) {
			
			switch(value)
			{
			case 0: return "m: "; break;
			case 1: return "in: "; break;
			case 2: return "ft: "; break;
			}

		};

		switch(units)
		{	
		case 0:
			std::cout << unity(units);
			std::cin >> InputValue;
			values.push_back( InputValue * 100 );
			break;
		case 1:
			std::cout << unity(units);
			std::cin >> InputValue;
			values.push_back( InputValue * 2.54 );
			break;
		case 2:
			std::cout << unity(units);
			std::cin >> InputValue;
			values.push_back(InputValue * 30.48 );
			break;
		case 3:
			for(auto &value : values)
				std::cout << value << " cm" << std::endl;
			return;
		default: 
			std::cout << "Keine gueltige Eingabe";
		}

		std::cout << "Eingabe: ";
		
	}
}

void vector_lesson5()
{
	int value = 0;
	int t[7] {1, 2, 3, 4, 5, 6, 7 };

	auto size = sizeof(t) / sizeof(t[0]);
	
	for (int i = 1; i < size+1; i++)
		value += i;
	
	std::cout << "Zentralwert: " << value / size;
}

