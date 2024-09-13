#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>
#include "huffman.cpp"

using namespace std;

int main(){

		string input = "AAAAAABCCCCCCDDEEEEE";
		unordered_map<char, string> output = huffman::getCode(input);
		string encoded = huffman::encode(input, output);
		cout << encoded << endl;

		
}
