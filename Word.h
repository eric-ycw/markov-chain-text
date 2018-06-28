#ifndef WORD_INCLUDED
#define WORD_INCLUDED
#include <vector>
#include <string>
#include <random>
class Word {
public:
	/*INITIALIZATION*/
	//Default constructor
	Word() {};
	//Explicit constructor
	Word(std::string s) { wstring = s; }
	//Word data structure
	struct wordStruct {
		std::string strstring;
		int weight;
	};
	//Choice vector
	std::vector<wordStruct> choiceVec;

	/*SETTERS*/
	void setString(std::string);
	void addChoice(std::string, int);

	/*GETTERS*/
	std::string getString();
	int getWeightSum();
	std::string getNextWord(std::vector<Word>);

private:
	std::string wstring;
};
#endif