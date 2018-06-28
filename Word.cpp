#include "stdafx.h"
#include "Word.h"
#include <iostream>

/*SETTERS*/
void Word::setString(std::string s) { wstring = s; }
void Word::addChoice(std::string s, int w) {
	wordStruct dummystruct;
	dummystruct.strstring = s;
	dummystruct.weight = w;
	choiceVec.push_back(dummystruct);
}

/*GETTERS*/
std::string Word::getString() { return wstring; }
//Get total weight sum
int Word::getWeightSum() {
	int sum = 0;
	for (int z = 0; z < choiceVec.size(); z++) {
		sum += choiceVec.at(z).weight;
	}
	return sum;
}
//Get next word
std::string Word::getNextWord(std::vector<Word> wV) {
	//Initialization
	int randval;
	std::string nextstring;

	//Pick a string from choice vector
	std::random_device dseed;
	std::mt19937 generator(dseed());
	if (getWeightSum() == 0) {
		//To prevent uniform_int error when b > a
		std::uniform_int_distribution<int> wd(0, 1);
		randval = wd(generator);
	}
	else {
		std::uniform_int_distribution<int> wd(1, getWeightSum());
		randval = wd(generator);
	}
	//Decrement randval until next word is found
	if (choiceVec.size() > 1) {
		for (int d = 0; d < choiceVec.size(); d++) {
			if ((randval - choiceVec.at(d).weight) > 0) {
				randval -= choiceVec.at(d).weight;
			}
			else {
				nextstring = choiceVec.at(d).strstring;
				break;
			}
		}
	}
	//Pick only choice
	else if (choiceVec.size() == 1) {
		nextstring = choiceVec.at(0).strstring;;
	}
	//If no choice, choose a random word from wordVec
	else if (choiceVec.size() == 0) {
		std::cout << std::endl << std::endl;
		std::random_device sseed;
		std::mt19937 generatortwo(sseed());
		std::uniform_int_distribution<int> wdd(0, wV.size() - 1);
		randval = wdd(generatortwo);
		nextstring = wV.at(randval).getString();
	}
	return nextstring;
}