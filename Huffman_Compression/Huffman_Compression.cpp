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


	void SortCharacterFrequencies()
	{
		std::pair<char,int> x;

		for (int i = 0; i < characterFrequency.size(); i++)
		{
			for (int j = i + 1; j < characterFrequency.size(); j++)
			{
				if (characterFrequency[i].second > characterFrequency[j].second)
				{
					x = characterFrequency[i];
					characterFrequency[i] = characterFrequency[j];
					characterFrequency[j] = x;
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


struct Node
{
	std::pair<char, int> value;
	Node* left = NULL;
	Node* right = NULL;

	Node(std::pair<char, int> data)
	{
		value = data;
	}

	void insert(std::pair<char, int> a)
	{
		if (a.second < value.second)
		{
			if (left != NULL)
			{
				insert(a);
			}
			else
			{
				left = &Node(a);
			}
		}
		else
		{
			if (right != NULL)
			{
				insert(a);
			}
			else
			{
				right = &Node(a);
			}
		}
	}
};

int main()
{
	std::string text;

	std::getline(std::cin, text);

	GetCharacterFrequency something(text);

	something.SortCharacterFrequencies();

	something.PrintVectors();

	system("pause");
}