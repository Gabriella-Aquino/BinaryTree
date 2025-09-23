#ifndef NO_H 
#define NO_H

struct Node
{
  int value;
  Node *leftChild;
  Node *rightChild;

  Node(int v) : value(v), leftChild(nullptr), rightChild(nullptr) {}
};

#endif