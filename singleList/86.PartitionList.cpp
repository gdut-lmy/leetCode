//
// Created by lmy on 2022/10/9.
//

#include "common.h"


class Solution {
public:
    //86.分隔链表
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        ListNode *p1 = dummy1, *p2 = dummy2;
        ListNode *p = head;
        while (p != nullptr) {
            if (p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            ListNode *temp = p->next;
            p->next = nullptr;
            p = temp;
        }
        p1->next = dummy2->next;
        return dummy1->next;
    }
};


int main() {
    Solution s;

    ListNode *s1 = create_linkedlist({1, 4, 3, 2, 5, 2});
    ListNode *res = s.partition(s1, 3);
    printList(res);
    clear(res);
    return 0;
}