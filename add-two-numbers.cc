#include <iostream>
using namespace std;

/**
 * @brief Definition for singly-linked list.
 * 
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *, ListNode *);

int main(int argc, char *argv[])
{
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode *sumList = addTwoNumbers(l1, l2);
    while (sumList != nullptr)
    {
        cout << sumList->val << "\n";
        sumList = sumList->next;
    }
    return -1;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int total = 0;
    ListNode *sumList = new ListNode();
    ListNode **temp = &sumList;

    while (l1 != nullptr || l2 != nullptr || total > 0)
    {
        if (l1 != nullptr)
        {
            total += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            total += l2->val;
            l2 = l2->next;
        }
        (*temp) = new ListNode(total % 10);
        total = total / 10;
        temp = &((*temp)->next);
    }
    return sumList;
}