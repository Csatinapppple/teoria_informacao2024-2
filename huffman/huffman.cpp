#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>

namespace huffman{

	class Node{
		char data;// if data is 0 the its just a internal node.
		int frequency;
		Node *left = nullptr ,*right=nullptr;

		Node(char data, int frequency){
			this->data = data;
			this->frequency = frequency;
		}

		void traverse_tree(Node* head){

		}
	};

	std::unordered_map<char, std::string> generateCode(std::vector<Node> heap){
		
	}

	bool cmp(std::pair<char, int>& a, 
					std::pair<char, int>& b) 
	{ 
			return a.second < b.second; 
	} 
	
	// Function to sort the map according 
	// to value in a (key-value) pairs 
	std::vector<std::pair<char, int> >  sort(std::unordered_map<char, int>& M) 
	{ 
	
			// Declare vector of pairs 
			std::vector<std::pair<char, int> > A; 
	
			// Copy key-value pair from Map 
			// to vector of pairs 
			for (auto& it : M) { 
					A.push_back(it); 
			} 
	
			// Sort using comparator function 
			std::sort(A.begin(), A.end(), cmp); 
	
			// Print the sorted value 
			for (auto& it : A) { 
	
					std::cout << it.first << ' '
							<< it.second << std::endl; 
			}

			return A; 
	} 

	std::string encode(std::string input){
		std::string ret;

		std::unordered_map<char, int> occurrences;


		for (char c: input){
			occurrences[c]=occurrences[c]+=1;
		}

		for (auto& elm: occurrences)
			std::cout << elm.first << " " << elm.second << "\n";

		sort(occurrences);

		return ret;
	}
}