//
// Created by lmy on 2022/10/9.
//

#include "common.h"

class Solution {

public:
    //21.MergeTwoSortedLists
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        ListNode *p1 = list1;
        ListNode *p2 = list2;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;
        }

        if (p1 != nullptr) {
            p->next = p1;
        }

        if (p2 != nullptr) {
            p->next = p2;
        }

        return dummy->next;
    }
};

int main() {
    Solution s;

    ListNode *s1 = create_linkedlist({1, 5, 9, 10});
    ListNode *s2 = create_linkedlist({2, 4, 7, 8});

    ListNode *res = s.mergeTwoLists(s1, s2);
    printList(res);
    clear(res);
    return 0;
}