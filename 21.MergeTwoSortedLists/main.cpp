//
// Created by lmy on 2022/10/9.
//

#include "solution.h"
#include "iostream"

using namespace std;

ListNode *create_linkedlist(std::initializer_list<int> lst) {
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : nullptr;
    for (ListNode *cur = head; iter != lst.end(); cur = cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

void clear(ListNode *head) {
    while (head) {
        ListNode *del = head;
        head = head->next;
        delete del;
    }
}

void printList(ListNode *head) {
    for (ListNode *cur = head; cur; cur = cur->next)
        cout << cur->val << "->";
    cout << "\b\b  " << endl;
}


int main() {

    Solution s;

    ListNode *s1 = create_linkedlist({1, 3, 5, 6});

    ListNode *s2 = create_linkedlist({2, 4, 7, 8});

    ListNode *res = s.mergeTwoLists(s1, s2);

    printList(res);


    return 0;
}