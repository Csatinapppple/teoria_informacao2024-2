#include <stdio.h>
#include "minHeap.cpp"

int main()
{
  using namespace std;
	string input = "AAAAAABCCCCCCDDEEEEE";
	vector<Symbol*> test = {
		new Symbol(0,0)
	};
	MinHeap mh(test.size());
	mh.buildHeap(test);
	mh.printHeap();

  return 0;
}
