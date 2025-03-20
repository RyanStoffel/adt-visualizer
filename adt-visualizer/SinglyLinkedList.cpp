#include "SinglyLinkedList.hpp"
#include <iostream>
using namespace std;

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr) {}

void SinglyLinkedList::appendNode(int value) {
  Node *newNode = new Node(value);
  if (!head) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void SinglyLinkedList::prependNode(int value) {
  Node *newNode = new Node(value);
  if (!head) {
    head = tail = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
}

void SinglyLinkedList::insertNodeAfter(int value, int afterValue) {
  Node *currentNode = head;
  while (currentNode) {
    if (currentNode->value == afterValue) {
      Node *newNode = new Node(value);
      newNode->next = currentNode->next;
      currentNode->next = newNode;
      if (currentNode == tail) {
        tail = newNode;
      }
      return;
    }
    currentNode = currentNode->next;
  }
  cout << "Cannot insert. Node " << afterValue << " does not exist in the list."
       << endl;
}

void SinglyLinkedList::removeNodeAfter(int value) {
  Node *currentNode = head;
  while (currentNode) {
    if (currentNode->value == value) {
      Node *nodeToRemove = currentNode->next;
      if (nodeToRemove) {
        currentNode->next = nodeToRemove->next;
        if (nodeToRemove == tail) {
          tail = currentNode;
        }
        delete nodeToRemove;
      } else {
        cout << "There is no node after " << value << " to remove." << endl;
      }
      return;
    }
    currentNode = currentNode->next;
  }
  cout << "Cannot remove node. Node " << value << " does not exist in the list."
       << endl;
}

int SinglyLinkedList::searchForNode(int value) {
  Node *currentNode = head;
  while (currentNode) {
    if (currentNode->value == value) {
      return 1;
    }
    currentNode = currentNode->next;
  }
  return 0;
}

bool SinglyLinkedList::isEmpty() { return head == nullptr; }

void SinglyLinkedList::printList() {
  Node *currentNode = head;
  while (currentNode) {
    cout << currentNode->value << " -> ";
    currentNode = currentNode->next;
  }
  cout << "NULL" << endl;
}

vector<int> SinglyLinkedList::toVector() {
  vector<int> result;
  Node *current = head;
  while (current) {
    result.push_back(current->value);
    current = current->next;
  }
  return result;
}
