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


	Node* generateAdaptiveHuffman(std::string input){
		using namespace std;
		priority_queue<Node*, vector<Node*>, greater_ptr> minHeap;
		Node *top = new Node(0,0,true);	
		minHeap.push(top);

		for(char c:input){
			min					
		}

		return nullptr;
	}

}
