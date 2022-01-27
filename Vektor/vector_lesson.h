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
