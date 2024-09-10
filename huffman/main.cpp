#include <iostream>
#include <unordered_map>

std::string encode(std::string input){
	std::string ret;

	std::unordered_map<char, int> occurrences;


	for (char c: input){
		occurrences[c]=occurrences[c]+=1;
	}

	for (auto& elm: occurrences)
		std::cout << elm.first << " " << elm.second << "\n";


	return ret;
}

int main(){

		std::string input = "AABCBAD";

		std::string output = encode(input);

}