#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct GetCharacterFrequency
{
	std::vector<std::pair<char, int>> characterFrequency;

	bool LetterIsFound(std::vector<std::pair<char, int>> x, char y)
	{
		for (auto i : x)
		{
			if (i.first == y)
				return true;
		}
		return false;	
	}

	void AddToCharacterFrequency(char a)
	{
		for (auto &i : characterFrequency)
		{
			if (i.first == a)
				i.second++;
		}
	}

	GetCharacterFrequency(std::string word)
	{
		for (int i = 0; word[i] != '\0'; i++)
		{
			if (LetterIsFound(characterFrequency, word[i]))
				AddToCharacterFrequency(word[i]);
			else
				characterFrequency.push_back(std::make_pair(word[i], 1));
		}
	}


	void SortFrequenciesAndCharacters()
	{
		int intTemp;
		for (int i = 0; i < characterFrequency.size(); i++)
		{
			for (int j = i + 1; j < characterFrequency.size(); j++)
			{
				if (characterFrequency[i].second > characterFrequency[j].second)
				{
					intTemp = characterFrequency[i].second;
					characterFrequency[i].second = characterFrequency[j].second;
					characterFrequency[j].second = intTemp;
				}			
			}
		}
	}

	void PrintVectors()
	{
		for (auto i : characterFrequency)
			std::cout << i.first << "-" << i.second << "\t";
		std::cout << std::endl;
	}
};

/*
struct CreateTree
{
	CreateTree(std::vector<char> a, std::vector<int> b)
	{
		while ()
	}
};*/

int main()
{
	std::string text;

	std::cin >> text;

	GetCharacterFrequency something(text);

	//something.SortFrequenciesAndCharacters();

	something.PrintVectors();

	system("pause");
}