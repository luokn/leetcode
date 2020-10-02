#pragma once
#include "leetcode.h"

using namespace utils;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, const int n) {
        if (head == nullptr) {
            return head;
        }
        ListNode* target  = head;
        int       counter = 0;
        for (auto cur = head; cur != nullptr; cur = cur->next, ++counter) {
            if (counter > n) {
                target = target->next;
            }
        }
        if (counter == n) {
            return head->next;
        }
        target->next = target->next->next;
        return head;
    }
};

inline void test() {
    Solution   solution;
    const auto nodes = make_nodes({1});
    print_nodes(solution.removeNthFromEnd(nodes, 1));
}
