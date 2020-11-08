#include <iostream>
#include <functional>
#include <fstream>
#include <string>
#include "multimap.h"

void readFile(Multimap<std::string, std::string>& multimap) {
	std::string line;
	std::ifstream file("data2.in");
	if (file.is_open()) {
		while (std::getline(file, line))
		{
			//reads file line by line, splits word from definition from the first space
			size_t pos = line.find(" ");
			std::string key = line.substr(0, pos);
			std::string value = line.substr(pos + 1);
			//adds word + def to multimap as a pair of key+value
			multimap.set(key, value);
		}
		file.close();
	}
	else {
		std::cout << " ERROR OPENING FILE ! EXITING!" << std::endl;
		exit(1);
	}
}

void searchDef(Multimap<std::string, std::string> multimap, std::string key) {
	//prints to console  definition of searched word
	std::vector<std::string> def = multimap.getValues(key);
	std::cout << key << ": " << std::endl;
	for (int i = 0; i < def.size(); i++) {
		std::cout << def[i] << std::endl;
	}
}

int main()
{
	Multimap<std::string, std::string> multimap;
	readFile(multimap);
	std::cout << "Type the word you need the definition of:" << std::endl;
	std::string word;
	std::cin >> word;
	searchDef(multimap, word);
	return 0;
}