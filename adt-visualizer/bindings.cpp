#include "SinglyLinkedList.hpp"
#include <emscripten/bind.h>
#include <iostream>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(singly_linked_list_module) {
  class_<SinglyLinkedList>("SinglyLinkedList")
      .constructor<>()
      .function("appendNode", &SinglyLinkedList::appendNode)
      .function("prependNode", &SinglyLinkedList::prependNode)
      .function("insertNodeAfter", &SinglyLinkedList::insertNodeAfter)
      .function("removeNodeAfter", &SinglyLinkedList::removeNodeAfter)
      .function("searchForNode", &SinglyLinkedList::searchForNode)
      .function("isEmpty", &SinglyLinkedList::isEmpty)
      .function("printList", &SinglyLinkedList::printList)
      .function("toVector", &SinglyLinkedList::toVector);
}

// Dummy main to ensure embind registration is linked in.
int main() {
  // In a modularized build for the web you typically don't use main,
  // but having a definition here ensures that the static constructors for
  // embind are not discarded.
  return 0;
}
