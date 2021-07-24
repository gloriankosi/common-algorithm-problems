#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *);

int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(
      1,
      new ListNode(
          1,
          new ListNode(
              2, new ListNode(
                     3, new ListNode(3, new ListNode(4, new ListNode(4)))))));

  auto nl = deleteDuplicates(l1);
  while (nl) {
    cout << nl->val << "\n";
    nl = nl->next;
  }
  return 0;
}
/**
 * @brief
 * @param l1
 * @return ListNode*
 */
ListNode *deleteDuplicates(ListNode *l1) {
  ListNode *node = new ListNode();
  ListNode *head = node;

  if (!l1) {
    return l1;
  }
  while (l1 && l1->next) {
    if (l1->val != l1->next->val) {
      head->next = l1;
      head = head->next;
    }
    l1 = l1->next;
  }
  if (l1 != l1->next) {  // Get the last element
    head->next = l1;
    head = head->next;
  }
  node = node->next;  // Get rid of head
  delete head;
  return node;
}