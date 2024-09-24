#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

namespace huffman
{	
	class Node;
	Node* generated;


	class Node
	{
	public:
		char data; // if data is 0 its a internal node.
		int frequency;
		Node *left = nullptr, *right = nullptr;
    bool nyt = true;
		Node(char data, int frequency)
		{
			this->data = data;
			this->frequency = frequency;
		}
	};

	struct greater_ptr
	{
		bool operator()(Node *l, Node *r)
		{
			return l->frequency > r->frequency;
		}
	};

	
	std::priority_queue<Node *, std::vector<Node *>, greater_ptr> minHeap;

	Node* generateAdaptiveHuffman(std::string input){

		std::string ret;

	}

}
