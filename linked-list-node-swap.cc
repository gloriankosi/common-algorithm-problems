#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *);

int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(
      1, new ListNode(
             2, new ListNode(
                    3, new ListNode(4, new ListNode(5, new ListNode(6))))));
  auto nl = swapPairs(l1);
  while (nl) {
    cout << nl->val << "\n";
    nl = nl->next;
  }
  return 0;
}

ListNode *swapPairs(ListNode *head) {
  if (!head || !head->next) {
    return head;
  }
  auto node = head;
  ListNode *temp = nullptr;
  if (node->next) {
    temp = node->next;
    head->next = swapPairs(node->next);
    temp->next = node;
    node = temp;
  }
  return node;
}