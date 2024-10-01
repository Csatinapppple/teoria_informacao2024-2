#include <stdio.h>
#include "maxHeap.cpp"

int main()
{
  using namespace std;
	string input = "AAAAAABCCCCCCDDEEEEE";

	MaxHeap mh;

	mh.handleSymbol('s');
	mh.handleSymbol('o');
	mh.handleSymbol('o');
	mh.handleSymbol('s');
	mh.handleSymbol('s');
	mh.handleSymbol('o');
	mh.handleSymbol('o');
	mh.handleSymbol('e');

	mh.printHeap(mh.head, " root");
	cout << mh.easy_access['s']->level << "\n";
	cout << mh.easy_access['o']->father->frequency << "\n";
	cout << "check" << '\n';
  return 0;
}
