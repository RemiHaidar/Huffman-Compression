// Huffman compression/encoding

#include <iostream>
#include <vector>
#include <string>
#include <queue>

// Strings are used instead of chars so the letters can be found in the
// Huffman tree in a more efficient way (see further in code).

std::vector<std::pair<std::string, int>> characterFrequency;

struct GetCharacterFrequency
{
private:
	// Checks if letter is already found in vector
	bool LetterIsFound(std::vector<std::pair<std::string, int>> x, std::string y)
	{
		for (auto i : x) {
			if (i.first == y) { return true; }
		}	return false;
	}
	// Adds to character frequency if letter is already found
	void AddToCharacterFrequency(std::string a)
	{
		for (auto& i : characterFrequency)
		{
			if (i.first == a) { i.second++; }
		}
	}
public:
	void main(std::string word)
	{
		std::string temp;
		// Find characters and their frequencies
		for (int i = 0; word[i] != '\0'; i++)
		{
			temp = word[i];
			if (LetterIsFound(characterFrequency, temp)) { AddToCharacterFrequency(temp); }
			else { characterFrequency.push_back(std::make_pair(temp, 1)); }
		}
	}
};

// Node object
struct Node
{
	std::string letter;
	int frequency;
	Node* right;
	Node* left;

	Node(std::string a, int b)
	{
		right = NULL;
		left = NULL;
		letter = a;
		frequency = b;
	}
};

// operator overload for priority_queue
struct compare
{
	bool operator()(Node* left, Node* right)
	{
		return (left->frequency > right->frequency);
	}
};

std::priority_queue <Node*, std::vector<Node*>, compare> nodes;

void CreateTree()
{
	Node* left;
	Node* right;
	Node* parent;

	// Creates the nodes
	for (auto i : characterFrequency)
		nodes.push(new Node(i.first, i.second));

	// Creates the tree
	while (nodes.size() > 1)
	{
		left = nodes.top();
		nodes.pop();
		right = nodes.top();
		nodes.pop();
		parent = new Node(left->letter + right->letter, left->frequency + right->frequency);
		parent->left = left;
		parent->right = right;
		nodes.push(parent);
	}
}

// Check if letter was already encoded
bool LetterFound(std::vector<std::pair<std::string, std::string>> a, std::string b)
{
	for (auto i : a)
	{
		if (i.first == b)
		{
			return true;
		}
	}
	return false;
}

// Stores codes
std::vector<std::pair<std::string, std::string>> codes;

// Function that displays code of letter given in as a parameter
void HuffmanCode(Node* root, std::string character)
{
	static std::string code = "";
	std::string temp;

	// Check if letter is already found
	if (!LetterFound(codes, character))
	{
		// If nodes contains letter, display code
		if (root->letter == character)
		{
			codes.push_back(std::make_pair(character, code));
		}
		else
		{
			// Check the left node
			for (int j = 0; j < root->left->letter.size(); j++)
			{
				temp = root->left->letter[j];
				if (temp == character)
				{
					code += "0";
					HuffmanCode(root->left, character);
				}
			}

			// Check the right node
			for (int j = 0; root->right->letter[j] != '\0'; j++)
			{
				temp = root->right->letter[j];
				if (temp == character)
				{
					code += "1";
					HuffmanCode(root->right, character);
				}
			}
		}
	}

	code.clear();
}

// Main function
void GetHuffmanCodes(std::string text)
{
	std::string temp;

	GetCharacterFrequency characterfrequency;
	characterfrequency.main(text);

	CreateTree();

	// Get huffman code of each letter
	for (int i = 0; text[i] != '\0'; i++)
	{
		temp = text[i];
		HuffmanCode(nodes.top(), temp);
	}

	std::cout << "[CODES] :" << std::endl;

	// Display letters and their equivalent codes
	for (auto i : codes)
	{
		std::cout << i.first << " : " << i.second << std::endl;
	}
}

void DisplayCompressedText(std::vector<std::pair<std::string, std::string>> a, std::string b)
{
	std::cout << "[COMPRESSED TEXT] :" << std::endl;

	std::string temp;
	for (int i = 0; b[i] != '\0'; i++)
	{
		temp = b[i];
		for (auto j : codes)
		{
			if (j.first == temp)
				std::cout << j.second;
		}
	}
}


int main()
{
	std::string text;
	std::getline(std::cin, text);

	GetHuffmanCodes(text);

	DisplayCompressedText(codes, text);

	std::cin.ignore();
}