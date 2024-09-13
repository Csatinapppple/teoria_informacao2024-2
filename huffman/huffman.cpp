#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

namespace huffman{

	class Node{
	public:
		char data;// if data is 0 its a internal node.
		int frequency;
		Node *left = nullptr ,*right=nullptr;

		Node(char data, int frequency){
			this->data = data;
			this->frequency = frequency;
		}

	};

	struct greater_ptr{
		bool operator()(Node* l, Node* r){
			return l->frequency > r->frequency;
		}
	};

	Node* generateTree(
			std::priority_queue<Node*, std::vector<Node*>, greater_ptr> minHeap){
		Node *ret = nullptr, *left = nullptr, *right =nullptr, *top = nullptr;

		while(minHeap.size()>1){
			left = minHeap.top();minHeap.pop();
			right = minHeap.top();minHeap.pop();

			top = new Node(0, left->frequency+right->frequency);
			top->left = left,top->right = right;
			minHeap.push(top);


		}

		ret = minHeap.top();

		return ret;
	}
	
	void getCodes(
			Node* root,
			std::string str,
			std::unordered_map<char, std::string>& huffmanCode){
			if (root == nullptr){
					return;
			}

			if (root->left == nullptr && root->right == nullptr) {
					huffmanCode[root->data] = str;
			}

			getCodes(root->left, str + "0", huffmanCode);
			getCodes(root->right, str + "1", huffmanCode);
	}

	std::unordered_map<char, std::string> getCode(std::string input){
		std::unordered_map<char, int> occurrences;
		std::priority_queue<Node*, std::vector<Node*>,greater_ptr> minHeap;

		for (char c: input)
			occurrences[c]=occurrences[c]+=1;
		for (auto& elm: occurrences){
			std::cout << elm.first << " " << elm.second << "\n";
			minHeap.push(new Node(elm.first, elm.second));
		}

		Node* root = generateTree(minHeap);
		std::unordered_map<char, std::string> codes;
		getCodes(root,"",codes);
		for (auto& elm: codes){
			std::cout << elm.first << " " << elm.second << "\n";
		}

		return codes;
	}

	std::string encode(std::string input, std::unordered_map<char, std::string> code){
		std::string ret;

		for(char a: input){
			ret += code[a];
		}

		return ret;
	}

}
