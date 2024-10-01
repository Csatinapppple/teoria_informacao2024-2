// C++ Program for implementing Min Heap
#include <iostream>
#include <vector>
#include <climits>
#include <cstdint>
#include <unordered_map>

#define NYT 257
#define INTERNAL 258
#define LEFT 0
#define RIGHT 1
#define TOP 2
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
        
        if (isSymbolInTree(symbol)) iterateSymbol(symbol);
        else insertSymbol(symbol);

        balanceTree(head);
    }

    void swap_ptr(Node* n1, Node*n2){

    }

    void iterateSymbol(short symbol){
        
        Node* current_symbol = easy_access[symbol];
        current_symbol->frequency++;
        if (current_symbol->level == 1){ 
            current_symbol->father->frequency=
                current_symbol->father->right->frequency +
                current_symbol->father->left->frequency;
            return;
        }

        Node* symbol_above = node_at_level[current_symbol->level-1];

        if(current_symbol->frequency > symbol_above->frequency){
            Node* internal_current_symbol = current_symbol->father;
            Node* internal_symbol_above = symbol_above->father;

            int current_symbol_level = current_symbol->level;
            int symbol_above_level = symbol_above->level;

            if (internal_symbol_above->left == symbol_above){
                current_symbol->father = internal_symbol_above;
                internal_symbol_above->left = current_symbol;
                current_symbol->level = symbol_above_level;

                symbol_above->father = internal_current_symbol;
                internal_current_symbol = 
            }            

        }else {

            Node* top_from_current = current_symbol->father;
            while(top_from_current!=nullptr){
                top_from_current->frequency=
                    top_from_current->right->frequency +
                    top_from_current->left->frequency;
                top_from_current=top_from_current->father;
            }
        }




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
			top_from_internal->frequency=
                top_from_internal->right->frequency +
                top_from_internal->left->frequency;
			top_from_internal=top_from_internal->father;
		}

		//cout << "symbol: " << symbol << " parent: " << new_node->father->data << "\n";


	}

    bool isSymbolInTree(short symbol){
        return (easy_access.find(symbol) == easy_access.end()) ? false : true;
    }

	// Function to print the values of  the  min heap
	void printHeap(Node* head,string direction) const {
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

		cout << "data: "<< data_str  << " frequency: " << root->frequency << direction <<"\n";

		printHeap(root->left, " left");
		printHeap(root->right, " right");

	}
};

