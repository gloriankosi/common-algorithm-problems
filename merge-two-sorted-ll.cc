/**
 * @file merge-two-sorted-ll.cc
 * @brief
 * Merge two sorted linked lists
 * g++ -g -Wall -std=c++2a merge-two-sorted-ll.cc -o mll
 */
#include <iostream>
using namespace std;
/**
 * @brief
 * Node Struct
 */
struct Node {
  int value;
  Node *next = nullptr;
  Node() {}
  Node(int value, Node *next) : value(value), next(next) {}
  Node(int value) : value(value), next(nullptr) {}
};
Node *merge(Node *&, Node *&);

int main(int argc, char *argv[]) {
  // sample data 1
  Node *l1Root = new Node(
      1, new Node(
             2, new Node(
                    3, new Node(4, new Node(7, new Node(10, new Node(11)))))));
  // sample data 2
  Node *l2Root = new Node(
      1,
      new Node(
          2,
          new Node(
              11, new Node(
                      14, new Node(
                              17, new Node(18, new Node(19, new Node(20))))))));
  Node *mList = merge(l1Root, l2Root);
  while (mList != nullptr) {
    cout << mList->value << "\n";
    mList = mList->next;
  }
  return 0;
}
/**
 * @brief
 *
 * @param l1
 * @param l2
 * @return Node*
 */
Node *merge(Node *&l1, Node *&l2) {
  Node *mList = new Node();  // Head of new list
  Node *mListTail = mList;   // Tail of new list

  // return nullptr if no lists are available
  if (l1 == nullptr and l2 == nullptr) {
    return nullptr;
  }

  // if l1 is nullptr, l2 is merged list
  if (l1 == nullptr) {
    return l2;
  }

  // if l2 is nullptr, l1 is merged list
  if (l2 == nullptr) {
    return l1;
  }

  // get first elemnt of l1 and l2 and do comparisons,this step is to assign
  // mList and mListTail something for the while loop coming up
  if (l1->value <= l2->value) {
    mList = l1;
    mListTail = mList;
    l1 = l1->next;
  } else {
    mList = l2;
    mListTail = mList;
    l2 = l2->next;
  }
  while (l1 != nullptr and l2 != nullptr) {
    Node *node = new Node();  // node containing next element
    // if l1 is smaller than l2, l1 goes first, then increment l1 for next
    // comparison, l2 stays the same
    if (l1->value <= l2->value) {
      node = l1;
      l1 = l1->next;
    } else {
      node = l2;
      l2 = l2->next;
    }
    // insertion to new LL and increment to next node by tail
    mListTail->next = node;
    mListTail = mListTail->next;
  }
  // if l1 is longer than l2, then remaining (sorted) elements are in l1, else
  // l2 is longer and remaining (sorted) elements are in l2. Assign to tail
  if (l1 != nullptr) {
    mListTail->next = l1;
  } else if (l2 != nullptr) {
    mListTail->next = l2;
  }
  return mList;
}