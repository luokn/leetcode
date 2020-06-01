#pragma once

#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int32_t val = 0, flow = 0;
        ListNode* res = nullptr;
        ListNode* ptr = nullptr;
        if (l1 != nullptr && l2 != nullptr) {
            val = l1->value + l2->value + flow;
            flow = val / 10;
            ptr = res = new ListNode(val % 10);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr && l2 != nullptr) {
            val = l1->value + l2->value + flow;
            l1 = l1->next;
            l2 = l2->next;
            flow = val / 10;
            ptr->next = new ListNode(val % 10);
            ptr = ptr->next;
        }

        while (l1 != nullptr) {
            val = l1->value + flow;
            l1 = l1->next;
            flow = val / 10;
            ptr->next = new ListNode(val % 10);
            ptr = ptr->next;
        }

        while (l2 != nullptr) {
            val = l2->value + flow;
            l2 = l2->next;
            flow = val / 10;
            ptr->next = new ListNode(val % 10);
            ptr = ptr->next;
        }

        if (flow != 0) { ptr->next = new ListNode(flow); }
        return res;
    }
};

inline void test() {
    ListNode* a = make_nodes({ 2,4,3 });
    ListNode* b = make_nodes({ 5,6,7,2 });

    Solution solution;
    ListNode* res = solution.addTwoNumbers(a, b);
    print_nodes(res);
    del_nodes(a);
    del_nodes(b);
    del_nodes(res);
}
