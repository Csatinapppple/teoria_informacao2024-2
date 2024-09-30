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
	int frequency; // se a frequencia for 0, é o nyt 
    Node* left=nullptr,  *right=nullptr,  *father=nullptr;
	Node(short data, int frequency){
		this->data=data,this->frequency=frequency;
	}
};
unordered_map<short, Node*> easy_access;
class MaxHeap {
public:

    Node* head;

    int size;         

    MaxHeap() {
        insertNYT();
    }

    // Function to restore heap order at index i
    void heapify(Node* i) {
        // Initialize smallest as root
        Node* smallest = i;    
        //  Find the Left child index
        Node* left = i->left;    
         // Find the Right child index
        Node* right = i->right;   
        
        // If left child is smaller than root
        if (left != nullptr && left->frequency > smallest->frequency)
            smallest = left;

        // If right child is smaller than the smallest so far
        if (right != nullptr && right->frequency > smallest->frequency)
            smallest = right;

        // If smallest is not root
        if (smallest != i) {
            heapify(smallest);                
        }
    }


    // Function to insert a new node into the min heap
    void insertNYT() {

        head = new Node(NYT,0);
        easy_access[NYT] = head;
        size++;
    }

    void insertSymbol(short symbol){

        Node* nyt = peekNYT();



    }

    // Function to get the topmost value from the min heap
    Node* peek() {
        if (size <= 0)
            return nullptr;  // Indicates that the heap is empty

        return head;
    }

    Node* peekNYT(){
        return easy_access[NYT];
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

