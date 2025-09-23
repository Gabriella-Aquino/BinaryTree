#include <iostream>
#include "no.h"

using namespace std;

class BinaryTree
{
private:
  Node *root;

public:
  BinaryTree(/* args */);
  ~BinaryTree();
  Node *getRoot();
  bool isEmpty();
  void inserir(int item);
  void find(Node &item, bool &found);
  Node *remove(int value, Node *currentNode);
  void remove(int value);
  void print(Node *root, int level);
  int countNodes(Node *root);
  int countNodes();
  Node *getMaxValue();
  Node *getMinValue();
  int height(Node *root);
  int height();
  int countLeaves(Node *root);
  int countLeaves();
  void printInOrder(Node *node);
  void printInOrder();
  void printPreOrder(Node *node);
  void printPreOrder();
  void printPostOrder(Node *node);
  void printPostOrder();
};

BinaryTree::BinaryTree()
{
  root = nullptr;
}

BinaryTree::~BinaryTree()
{
}

Node *BinaryTree::getRoot()
{
  return root;
}

bool BinaryTree::isEmpty()
{
  return (root == nullptr);
}

void BinaryTree::inserir(int item)
{
  Node *newNode = new Node(item);
  if (root == nullptr)
  {
    root = newNode;
  }
  else
  {
    Node *temp = root;
    while (temp != nullptr)
    {
      if (newNode->value < temp->value)
      {
        if (temp->leftChild == nullptr)
        {
          temp->leftChild = newNode;
          break;
        }
        else
        {
          temp = temp->leftChild;
        }
      }
      else
      {
        if (temp->rightChild == nullptr)
        {
          temp->rightChild = newNode;
          break;
        }
        else
        {
          temp = temp->rightChild;
        }
      }
    }
  }
}

void BinaryTree::find(Node &item, bool &found)
{
  found = false;
  Node *currentNode = root;
  while (currentNode != nullptr)
  {
    if (item.value < currentNode->value)
    {
      currentNode = currentNode->leftChild;
    }
    else if (item.value > currentNode->value)
    {
      currentNode = currentNode->rightChild;
    }
    else
    {
      found = true;
      item.value = currentNode->value;
      break;
    }
  }
}

Node *BinaryTree::remove(int value, Node *currentNode)
{
  if (currentNode == nullptr)
  {
    return nullptr;
  }

  if (value < currentNode->value)
  {
    currentNode->leftChild = remove(value, currentNode->leftChild);
  }
  else if (value > currentNode->value)
  {
    currentNode->rightChild = remove(value, currentNode->rightChild);
  }
  else
  {
    if (currentNode->leftChild == nullptr)
    {
      Node *temp = currentNode->rightChild;
      delete currentNode;
      return temp;
    }
    else if (currentNode->rightChild == nullptr)
    {
      Node *temp = currentNode->leftChild;
      delete currentNode;
      return temp;
    }
    else
    {
      Node *temp = currentNode->rightChild;
      while (temp->leftChild != nullptr)
      {
        temp = temp->leftChild;
      }

      currentNode->value = temp->value;
      currentNode->rightChild = remove(temp->value, currentNode->rightChild);
    }
  }
  return currentNode;
}

void BinaryTree::remove(int value)
{
  root = remove(value, root);
}

void BinaryTree::print(Node *root, int level = 0)
{
  if (root == nullptr)
  {
    return;
  }

  for (int i = 0; i < level; i++)
  {
    cout << "-";
  }

  cout << root->value << endl;

  print(root->leftChild, level + 1);
  print(root->rightChild, level + 1);
}

int BinaryTree::countNodes(Node *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  return 1 + countNodes(root->leftChild) + countNodes(root->rightChild);
}

int BinaryTree::countNodes()
{
  return countNodes(root);
}

Node *BinaryTree::getMaxValue()
{
  if (root == nullptr)
  {
    return nullptr;
  }

  Node *current = root;
  while (current->rightChild != nullptr)
  {
    current = current->rightChild;
  }
  return current;
}

Node *BinaryTree::getMinValue()
{
  if (root == nullptr)
  {
    return nullptr;
  }

  Node *current = root;
  while (current->leftChild != nullptr)
  {
    current = current->leftChild;
  }

  return current;
}

int BinaryTree::height(Node *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  int leftHeight = height(root->leftChild);
  int rightHeight = height(root->rightChild);

  return 1 + max(leftHeight, rightHeight);
}

int BinaryTree::height()
{
  return height(root) - 1;
}

int BinaryTree::countLeaves(Node *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  if (root->leftChild == nullptr && root->rightChild == nullptr)
  {
    return 1;
  }

  return countLeaves(root->leftChild) + countLeaves(root->rightChild);
}

int BinaryTree::countLeaves()
{
  return countLeaves(root);
}

void BinaryTree::printInOrder(Node *node)
{
  if (node != nullptr)
  {
    printInOrder(node->leftChild);
    cout << node->value << " ";
    printInOrder(node->rightChild);
  }
}

void BinaryTree::printInOrder()
{
  printInOrder(root);
}

void BinaryTree::printPreOrder(Node *node)
{
  if (node != nullptr)
  {
    cout << node->value << " ";
    printPreOrder(node->leftChild);
    printPreOrder(node->rightChild);
  }
}

void BinaryTree::printPreOrder()
{
  printPreOrder(root);
}

void BinaryTree::printPostOrder(Node *node)
{
  if (node != nullptr)
  {
    printPostOrder(node->leftChild);
    printPostOrder(node->rightChild);
    cout << node->value << " ";
  }
}

void BinaryTree::printPostOrder()
{
  printPostOrder(root);
}
