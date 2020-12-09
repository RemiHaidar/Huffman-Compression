#include <iostream>
#include <vector>
#include <string>

struct GetFrequency
{
	std::vector<char> characters;
	std::vector<int> frequency;

	bool LetterIsFound(std::vector<char> x, char y)
	{
		if (!x.empty())
		{
			for (int i = 0; i < x.size(); i++)
			{
				if (x[i] == y)
				{
					return true;
				}
			}

			return false;
		}
			
	}

	void AddToCharacterFrequency(char a)
	{
		for (int i = 0; i < characters.size(); i++)
		{
			if (characters[i] == a)
			{
				frequency[i]++;
			}
		}
	}

	GetFrequency(std::string word)
	{
		for (int i = 0; word[i] != '\0'; i++)
		{
			if (LetterIsFound(characters, word[i]))
			{
				AddToCharacterFrequency(word[i]);
			}
			else {
				characters.push_back(word[i]);
				frequency.push_back(1);
			}
		}
	}

	void PrintVectors()
	{
		for (int i = 0; i < characters.size(); i++)
		{
			std::cout << characters[i] << "\t";
		}

		std::cout << std::endl;

		for (int i = 0; i < frequency.size(); i++)
		{
			std::cout << frequency[i] << "\t";
		}
	}
};

int main()
{
	std::string text;

	std::cin >> text;

	GetFrequency something(text);

	something.PrintVectors();

	system("pause");
}