#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <map>
#include <string> 
#include <stdlib.h>
#include <ranges>

using std::cout;


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

void vector_lesson6()
{
	int firstUnit = 0;
	int UserInput = 0;
	int value = 50;
	std::cout << "Ist die Zahl grosser als " << value << "? \n-----------------------------\n1 = Ja | 0 = Nein \n-----------------------------\nEingabe: ";
	std::cin >> firstUnit;

	for (int i = 0; i < 7; i++)
	{

		if( firstUnit == 1 )
		{
			std::cout << "Ist deine Zahl? " << value << "? \n-----------------------------\n1 = Ja | 0 = Nein \n-----------------------------\nEingabe: ";
			std::cin >> UserInput;
			if(UserInput == 0)
			{
				value += 10;
			}else{
				std::cout << "Deine Zahl ist: " << value; 
				break;
			}

		}else{
			std::cout << "Ist deine Zahl? " << value << "? \n-----------------------------\n1 = Ja | 0 = Nein \n-----------------------------\nEingabe: ";
			std::cin >> UserInput;
			if(UserInput == 0)
			{
				value -= 10;
			}else{
				std::cout << "Deine Zahl ist: " << value; 
				break;
			}	
		
		}

	}
}

void vector_lesson7()
{
	double value1 = 0;
	double value2 = 0;
	char unit;
	std::cout << "Taschenrechner\n";
	std::cout << "Wert 1: ";
	std::cin>>value1;
	std::cout << "Wert 2: ";
	std::cin>>value2;

	std::cout << "---------------------------------------\nAddition +\nSubtraktion -\nMultiplikation *\n---------------------------------------\nEingabe: ";
	std::cin>>unit;
	
	switch(unit)
	{
		case '+': std::cout << "Ergebnis: " << value1 + value2; break;
		case '-': std::cout << "Ergebnis: " << value1 - value2; break;
		case '*': std::cout << "Ergebnis: " << value1 * value2; break;
	}

}

void vector_lesson8()
{
	int userInput = 0;
	std::vector<std::string> numbers { "eins", "zwei", "drei", "vier", "fuenf", "sechs", "sieben", "acht", "neun", "zehn" };
 

	std::cout << "Geben Sie eine Zahl ein: ";
	std::cin >> userInput;


	if( userInput <= 10 )
	{
		std::cout << numbers.at(userInput - 1);
	}else
	{
		std::cout << "Die eingegeben zahl, ist zu gross!";
	}


}


bool isNumber(const std::string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}


void vector_lesson9()
{	
	std::map<std::string, int> values { {"eins", 1},  {"1", 1},	
										{"zwei", 2},  {"2", 2}, 
										{"drei", 3},  {"3", 3},
										{"vier", 4},  {"4", 4},	
										{"fuenf", 5}, {"5", 5},
										{"sechs", 6}, {"6", 6},
										{"sieben", 7},{"7", 7},
										{"acht", 8},  {"8", 8},	
										{"neun", 9},  {"9", 9}, 
										{"zehn", 10}, {"10", 10} };
	std::string value1;
	std::string value2;
	char unit;
	
	std::cout << "Taschenrechner\n";
	
	std::cout << "Wert 1: ";
	std::cin>> value1;
	std::cout << "Wert 2: ";
	std::cin>> value2;

	std::cout << "---------------------------------------\nAddition +\nSubtraktion -\nMultiplikation *\n---------------------------------------\nEingabe: ";
	std::cin>>unit;
	
	switch(unit)
	{
		case '+': std::cout << "Ergebnis: " << values[value1] + values[value2]; break;
		case '-': std::cout << "Ergebnis: " << values[value1] - values[value2]; break;
		case '*': std::cout << "Ergebnis: " << values[value1] * values[value2]; break;
	}

}

void vector_lesson10()
{
	int userInput = 0;
	int wins = 0;
	int lost = 0;
	int drawn = 0;

	std::cout << "1: Schere, 2: Stein oder 3: Papier?: ";

	auto print = [&](){
		std::cout << "Punktestand: Gewonnen: " << wins << " Verloren: " << lost  << " Unentschieden: " << drawn << std::endl;
		std::cout << "---------------------------------------------------------------\n";
		std::cout << "1: Schere, 2: Stein oder 3: Papier?: ";
	};

	while(std::cin>>userInput)
	{
		system("cls");
		std::vector<std::string> name{ "Schere", "Stein", "Papier" };

		srand( time(NULL) ); 
		int randNum = rand() % 4; 
		if( randNum == 0 ) randNum = 1;

		std::cout << "Computer: " << name.at(randNum -1 ) << std::endl; 

		if( userInput == randNum ) 
		{	std::cout << "Unentschieden!" << std::endl;
			drawn++;
			print();
			continue;
		}

	switch(userInput){
		case 1:
			if( randNum == 2 ) { std::cout << "Verloren!"; lost++; } else { wins++; std::cout << "Gewonnen!"; }
		break;

		case 2:
			if( randNum == 3 ) { lost++; std::cout << "Verloren!"; } else { wins++; std::cout << "Gewonnen!"; }
		break;
		case 3:
			if( randNum == 1 ) { lost++; std::cout << "Verloren!"; } else { wins++; std::cout << "Gewonnen!"; }
		break;
		default:
			std::cout << "Falsche eingabe!";
	}

		std::cout << std::endl;
		print();

	}

}

void vector_lesson11()
{
	std::vector<int> primes;
	int count = 0;

	for (int i = 2; i <= 100; i++)
	{
		bool isPrimes = true;
		for (int j = 2; j < i; j++)
		{

			if( i % j == 0 )
			{ 
				isPrimes = false;
				break;
			}
		}

		if( isPrimes )
		{
			primes.push_back(i);
		}
	}

	for(auto &num : primes)
	{
		std::cout << num << std::endl;
	}

}

void vector_lesson12()
{
	std::vector<std::string> names;
	std::vector<int> score;
	std::string input;
	int scoreInput;

	auto print = []()
	{
		std::cout << "Geben Sie einen Namen ein: ";
	};

	print();
	while(std::cin>>input)
	{
		if(input == "Noname") break;

		std::cout << "Geben Sie einen Score ein: ";

		std::cin >> scoreInput;

		if(input != "")
		{
			names.push_back(input);
			score.push_back(scoreInput);
		}else{
			std::cout << "Geben Sie einen Namen an!";
		}
		print();
	}

	//std::cout << "Ausgabe: " << std::endl;

	//int i = -1;
	//for (auto &name : names)
	//{
	//	i++;
	//	std::cout << "Name: " << name << " Score: " << score.at(i) <<  "\n";
	//}


	std::cout << "Suche: Geben Sie die Punktzahl ein: ";
	std::cin >> scoreInput;

	int j = -1;
	for(auto &value : score)
	{
		if(scoreInput == value)
		{
			j++;
			std::cout << "Name: " << names.at(j) << " Punkte: " << value << std::endl;
		}
	}

}