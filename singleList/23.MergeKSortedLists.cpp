//
// Created by lmy on 2022/10/9.
//


#include "common.h"


class Solution {

    struct tmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

public:
//23.合并K个升序链表
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        priority_queue<ListNode *, vector<ListNode *>, tmp> pq;
        for (ListNode *head: lists) {
            if (head != nullptr)
                pq.push(head);
        }
        while (!pq.empty()) {
            ListNode *tmp = pq.top();
            pq.pop();
            p->next = tmp;
            if (tmp->next != nullptr)
                pq.push(tmp->next);
            p = p->next;
        }
        return dummy->next;
    }
};


int main() {
    Solution s;
    vector<ListNode *> test = {create_linkedlist({1, 4, 6, 7}), create_linkedlist({5, 7, 9, 10}),
                               create_linkedlist({3, 5, 7, 9})};

    ListNode *res = s.mergeKLists(test);
    printList(res);
    clear(res);
    return 0;
}