#include <stdio.h>
#include "maxHeap.cpp"

int main()
{
  using namespace std;
	string input = "AAAAAABCCCCCCDDEEEEE";

	MaxHeap mh;

	mh.insertSymbol('s');
	mh.insertSymbol('o');
	mh.insertSymbol('d');

	cout << mh.head->left->data << "\n";
	mh.printHeap(mh.head);
	cout << "check" << '\n';
  return 0;
}
