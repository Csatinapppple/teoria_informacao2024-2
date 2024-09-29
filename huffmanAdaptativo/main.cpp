#include <stdio.h>
#include "minHeap.cpp"

int main()
{
  using namespace std;
	string input = "AAAAAABCCCCCCDDEEEEE";
	vector<Symbol*> test;
	test.push_back(new Symbol(NYT,0));
	MinHeap mh(test.size());
	mh.buildHeap(test);
	mh.printHeap();

  return 0;
}
