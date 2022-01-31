#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>

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

void vector_leesion3()
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

void vector_leesion4()
{

	double InputValue = 0;
	int units;
	
	auto unit = [](double InputValue, int units){
		
		switch(units)
		{
		case 0:
			std::cout << InputValue * 100;
			break;
		case 1:
			std::cout << InputValue / 100;
			break;
		case 2:
			std:: cout << 1 * 2.54; 
			break;
		case 3:
			std::cout << 1 * 12; 
			break;
		default: 
			std::cout << "Keine gueltige Eingabe";
		}

	};

	std::cout << "Eingabe ( cm = 0, m = 1, in = 2, ft = 3 ): ";
	std::cin >> units;
	std::cin >> InputValue;	
	unit(InputValue, units);


}