#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

std::vector<std::pair<char, int>> characterFrequency;

struct GetCharacterFrequency
{
private:
	// Checks if letter is already found in vector
	bool LetterIsFound(std::vector<std::pair<char, int>> x, char y)
	{
		for (auto i : x) {
			if (i.first == y)
				return true;
		}
		return false;
	}
	//

	// Adds to character frequency if letter is already found
	void AddToCharacterFrequency(char a)
	{
		for (auto& i : characterFrequency)
		{
			if (i.first == a)
				i.second++;
		}
	}
	//
public:
	void main(std::string word)
	{
		// Find characters and their frequencies
		for (int i = 0; word[i] != '\0'; i++)
		{
			if (LetterIsFound(characterFrequency, word[i]))
			{
				AddToCharacterFrequency(word[i]);
			}
			else
			{
				characterFrequency.push_back(std::make_pair(word[i], 1));
			}
		}
		//
		// Prints vector of pairs
		for (auto i : characterFrequency)
			std::cout << i.first << "-" << i.second << "\t";
		std::cout << std::endl;
		//
	}
};
//


struct Node
{
	Node() {};

	std::vector<Node> nodes;
	char letter;
	int frequency;
	Node* left;
	Node* right;

	Node(char a, int b)
	{
		letter = a;
		frequency = b;
		left = NULL;
		right = NULL;
	}

	void CreateNodes()
	{
		for (auto i : characterFrequency)
		{
			nodes.push_back(Node(i.first, i.second));
		}
	}

	/*void PrintNodes()
	{
		for (int i = nodes.size() - 1; i >= 0; i--)
		{
			std::cout << nodes[i].letter << "-" << nodes[i].frequency << "\t";
		}
	}*/

	friend bool operator > (Node a, Node b)
	{
		return a.frequency > b.frequency;
	}

	void SortNodes()
	{
		Node temp;

		for (int i = 0; i < nodes.size(); i++)
		{
			for (int j = i + 1; j < nodes.size(); j++)
			{
				if (!(nodes[i] > nodes[j]))
				{
					temp = nodes[i];
					nodes[i] = nodes[j];
					nodes[j] = temp;
				}
			}
		}
	}
};



struct Tree : Node
{
	std::vector<Node> temp;

	
	std::string code;

	void createParentNode(Node& a, Node& b)
	{
		int parentFrequency = 0;
		Node parent;

		*parent.left = a;
		*parent.right = b;
		parent.frequency = a.frequency + b.frequency;
		parent.letter = '$';

		nodes.pop_back();
		nodes.pop_back();

		nodes.push_back(parent);
	}

	void createTree()
	{
		while (nodes.size() > 0)
		{
			SortNodes();
			createParentNode(nodes[0], nodes[1]);
		}
	}

	void PrintCode()
	{
		
	}

};


int main()
{
	std::string text;
	std::getline(std::cin, text);

	GetCharacterFrequency b;
	b.main(text);

	Tree a;
	a.createTree();

	std::cout << a.nodes[0].frequency;

	std::cin.ignore();

	//ooouuuuaaaaaaaaaaiiiiiiiiiiiisssssssssssss
}