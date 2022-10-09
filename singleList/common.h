//
// Created by lmy on 2022/10/9.
//

#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *create_linkedlist(std::initializer_list<int> lst);

void clear(ListNode *head);

void printList(ListNode *head);

#endif //LEETCODE_COMMON_H
