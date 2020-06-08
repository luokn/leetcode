#pragma once

#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *ln, ListNode *rn) {
        int32_t val = 0, flow = 0;
        ListNode *ret = nullptr, *cur = nullptr;

        if (ln != nullptr && rn != nullptr) {
            val = ln->value + rn->value + flow;
            flow = val / 10;
            cur = ret = new ListNode(val % 10);
            ln = ln->next;
            rn = rn->next;
        }

        while (ln != nullptr && rn != nullptr) {
            val = ln->value + rn->value + flow;
            ln = ln->next;
            rn = rn->next;
            flow = val / 10;
            cur->next = new ListNode(val % 10);
            cur = cur->next;
        }

        while (ln != nullptr) {
            val = ln->value + flow;
            ln = ln->next;
            flow = val / 10;
            cur->next = new ListNode(val % 10);
            cur = cur->next;
        }

        while (rn != nullptr) {
            val = rn->value + flow;
            rn = rn->next;
            flow = val / 10;
            cur->next = new ListNode(val % 10);
            cur = cur->next;
        }

        if (flow != 0) {
            cur->next = new ListNode(flow);
        }
        return ret;
    }
};

inline void test() {
    ListNode *a = make_nodes({2, 4, 3});
    ListNode *b = make_nodes({5, 6, 7, 2});

    Solution solution;
    ListNode *res = solution.addTwoNumbers(a, b);
    print_nodes(res);
    del_nodes(a);
    del_nodes(b);
    del_nodes(res);
}
