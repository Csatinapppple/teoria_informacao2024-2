// C++ Program for implementing Min Heap
#include <iostream>
#include <vector>
#include <climits>
#include <cstdint>
#include <unordered_map>

#define NYT 257
#define INTERNAL 258

using namespace std;


// Template for representing MinHeap
class Node {
public:
	short data; //
	int frequency,
        level; // se a frequencia for 0, é o nyt 
	Node* left=nullptr,  *right=nullptr,  *father=nullptr;
	Node(short data, int frequency, int level): 
        data(data), frequency(frequency), level(level){} 
};
class MaxHeap {
public:

	unordered_map<short, Node*> easy_access;
    unordered_map<int, Node*> node_at_level;
	Node* head=nullptr;

	int levels=0;         

	MaxHeap() {
		head = new Node(NYT, 0, levels);
		easy_access[NYT] = head;
	}



	// Function to insert a new node into the min heap
	void balanceTree(Node* root){

		if(root->right == nullptr || root->left == nullptr) return;

		if(root->left->frequency > root->right->frequency){
			Node* tmp = root->left;
			root->left = root->right;
			root->right = tmp;
		}

		balanceTree(root->left);
		balanceTree(root->right);

	}

    void handleSymbol(short symbol){
        
        balanceTree(head);
    }

    void iterateSymbol(short symbol){
        
        Node* node_from_symbol = easy_access[symbol];

    }

	void insertSymbol(short symbol){

        levels++;

		Node* nyt = easy_access[NYT];
        nyt->level=levels;

		Node* new_node = new Node(symbol,1,levels);

		easy_access[symbol] = new_node;
        node_at_level[levels] = new_node;

		cout << "creating symbol: " << symbol << "\n";

		Node* internal = new Node(INTERNAL, new_node->frequency + nyt->frequency, levels-1);
		Node* save_last_internal = nyt->father;
		internal->father = nyt->father;
		internal->right = new_node;
		internal->left = nyt;

		new_node->father = internal;
		nyt->father = internal;

		if(head->data==NYT)
			head=internal;
		else
			save_last_internal->left = internal;

		Node* top_from_internal = internal->father;

		while(top_from_internal!=nullptr){
			top_from_internal->frequency++;
			top_from_internal=top_from_internal->father;
		}

		//cout << "symbol: " << symbol << " parent: " << new_node->father->data << "\n";


	}

    bool isSymbolInTree(short symbol){
        return (easy_access.find(symbol) == easy_access.end()) ? false : true;
    }

	// Function to print the values of  the  min heap
	void printHeap(Node* head) const {
		Node* root = head;

		if (root == nullptr){
			return;
		}

		string data_str="";

		switch(root->data) {
			case NYT:
				data_str = "NYT";
				break;
			case INTERNAL:
				data_str = "INTERNAL";
				break;
			default:
				data_str = std::to_string(root->data);
				break;
		}

		cout << "data: "<< data_str  << " frequency: " << root->frequency << "\n";

		printHeap(root->left);
		printHeap(root->right);

	}
};

