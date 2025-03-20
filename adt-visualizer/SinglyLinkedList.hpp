#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <vector>
using namespace std;

class Node {
public:
  int value;
  Node *next;
  Node(int value) : value(value), next(nullptr) {}
};

class SinglyLinkedList {
public:
  Node *head;
  Node *tail;
  SinglyLinkedList();

  void appendNode(int value);
  void prependNode(int value);
  void insertNodeAfter(int value, int afterValue);
  void removeNodeAfter(int value);
  int searchForNode(int value);
  bool isEmpty();
  void printList();
  vector<int> toVector();
};

#endif
