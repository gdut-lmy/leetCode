//
// Created by lmy on 2022/10/9.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    struct tmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

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

#endif //LEETCODE_SOLUTION_H
