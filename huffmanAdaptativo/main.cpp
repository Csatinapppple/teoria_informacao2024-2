#include <stdio.h>
#include "huffmanAda.cpp"

int main()
{
  using namespace std;
  AdaptiveHuffman huffman;
  string encoded;

  // Encoding a string
  string input = "AAAAAABCCCCCCDDEEEEE";
  for (char c : input)
  {
    encoded += huffman.encode(c);
  }

  cout << "Encoded: " << encoded << endl;

  // Decoding the encoded string
  string decoded = huffman.decode(huffman.root,encoded);

  cout << "Decoded: " << decoded << endl;

  return 0;
}