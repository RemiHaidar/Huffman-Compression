#include <iostream>
#include <vector>
#include <string>
#include <queue>


std::vector<std::pair<char, int>> characterFrequency;

struct GetCharacterFrequency
{
private:
	// Checks if letter is already found in vector
	bool LetterIsFound(std::vector<std::pair<char, int>> x, char y)
	{
		for (auto i : x) {
			if (i.first == y) { return true; }
		}	return false;
	}
	//

	// Adds to character frequency if letter is already found
	void AddToCharacterFrequency(char a)
	{
		for (auto& i : characterFrequency)
		{
			if (i.first == a) { i.second++; }
		}
	}
	//
public:
	void main(std::string word)
	{
		// Find characters and their frequencies
		for (int i = 0; word[i] != '\0'; i++)
		{
			if (LetterIsFound(characterFrequency, word[i])) { AddToCharacterFrequency(word[i]); }
			else { characterFrequency.push_back(std::make_pair(word[i], 1)); }
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
	std::string letter;
	int frequency;
	Node* right;
	Node* left;

	Node(char a, int b)
	{
		right = NULL;
		left = NULL;
		letter = a;
		frequency = b;
	}
};

struct compare
{
	bool operator()(Node* left, Node* right)
	{
		return (left->frequency > right->frequency);
	}
};

std::priority_queue < Node*, std::vector<Node*>, compare> nodes;


void CreateTree()
{
	Node* left;
	Node* right;
	Node* parent;

	for (auto i : characterFrequency)
	{
		nodes.push(new Node(i.first, i.second));
	}

	while (nodes.size() > 1)
	{
		left = nodes.top();
		nodes.pop();
		right = nodes.top();
		nodes.pop();
		parent = new Node('#', left->frequency + right->frequency);
		parent->left = left;
		parent->right = right;
		parent->letter = left->letter + right->letter;
		nodes.push(parent);
	}
}

void GetNewCodes(Node* root, const char *letter)
{
	static std::string code = "";

	if (root->letter == letter)
	{
		std::cout << code;
	}
	else
	{
		for (int j = 0; j < root->left->letter.size(); j++)
		{
			if (root->left->letter[j] == *letter)
			{
				code = code + "0";
				GetNewCodes(root->left, letter);
			}
		}

		for (int j = 0; root->right->letter[j] != '\0'; j++)
		{
			if (root->right->letter[j] == *letter)
			{
				code = code + "1";
				GetNewCodes(root->right, letter);
			}
		}
	}
}

void HuffmanCodes(const char* text)
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		GetNewCodes(nodes.top(), &text[i]);
	}
}


int main()
{
	std::string text;
	std::getline(std::cin, text);

	const char* _text = text.c_str();

	GetCharacterFrequency a;
	a.main(text);
	CreateTree();

	for (int i = 0; i < text.size(); i++)
	{
		GetNewCodes(nodes.top(), (const char*)_text[i]);
	}

	//HuffmanCodes(text.c_str());

	std::cin.ignore();
	
	//ooouuuuaaaaaaaaaaiiiiiiiiiiiisssssssssssss
}
