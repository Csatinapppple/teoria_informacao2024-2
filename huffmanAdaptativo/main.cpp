#include <stdio.h>
#include "maxHeap.cpp"

int main()
{
  using namespace std;
	string input = "AAAAAABCCCCCCDDEEEEE";

	MaxHeap mh;

	mh.handleSymbol('s');
	mh.handleSymbol('s');

	mh.printHeap(mh.head, " root");
	cout << mh.easy_access['s']->father->frequency << "\n";
	cout << mh.easy_access['o']->frequency << "\n";
	cout << "check" << '\n';
  return 0;
}
