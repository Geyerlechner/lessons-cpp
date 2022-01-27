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

int main()
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

