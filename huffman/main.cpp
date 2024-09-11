#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>

bool cmp(std::pair<char, int>& a, 
        std::pair<char, int>& b) 
{ 
    return a.second < b.second; 
} 
 
// Function to sort the map according 
// to value in a (key-value) pairs 
void sort(std::unordered_map<char, int>& M) 
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

int main(){

		std::string input = "DDDDBBBBBBAABCBAD";

		std::string output = encode(input);

}