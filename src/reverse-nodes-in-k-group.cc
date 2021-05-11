#pragma once
#include "leetcode.h"

using namespace utils;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* node, const int k) {
        auto cur = node;
        int  counter;
        for (counter = 0; cur; ++counter) cur = cur->next;
        if (counter < k) return node;

        ListNode* last_tail = nullptr;
        ListNode* res       = nullptr;
        cur                 = node;
        for (auto i = 0; i < counter / k; ++i) {
            ListNode* new_head = nullptr;
            ListNode* new_tail = cur;
            for (auto j = 0; j < k; ++j) {
                const auto next = cur->next;
                cur->next       = new_head;
                new_head        = cur;
                cur             = next;
            }
            if (i == 0) {
                res = new_head;
            } else {
                last_tail->next = new_head;
            }
            last_tail = new_tail;
        }
        last_tail->next = cur;
        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution   solution;
    const auto nodes = make_nodes({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    print_nodes(nodes);
    const auto res = solution.reverseKGroup(nodes, 3);
    print_nodes(res);
    del_nodes(res);
}
