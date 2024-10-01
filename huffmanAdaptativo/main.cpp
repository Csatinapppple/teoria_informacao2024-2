#include <stdio.h>
#include "maxHeap.cpp"

int main()
{
  using namespace std;
	string input = "AAAAAABCCCCCCDDEEEEE";

	MaxHeap mh;

	mh.handleSymbol('s');
	mh.handleSymbol('o');

	cout << mh.head->left->data << "\n";
	mh.printHeap(mh.head);
	cout << "check" << '\n';
  return 0;
}
