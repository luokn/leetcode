#pragma once
#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
  public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr)
            return nullptr;
        ListNode *tail = nullptr;
        auto count = 1;
        for (tail = head; tail->next != nullptr; tail = tail->next)
            ++count;
        tail->next = head;
        for (auto i = 0; i < count - k % count; ++i) {
            head = head->next;
            tail = tail->next;
        }
        tail->next = nullptr;
        return head;
    };
};

inline void test() {
    Solution solution;
    const vector<int> vec{0};
    const auto node = make_nodes(vec);
    foreach (node, [](const int v) { cout << v << " "; })
        ;
    cout << endl;
    const auto res = solution.rotateRight(node, 4);
    foreach (res, [](const int v) { cout << v << " "; })
        ;
    del_nodes(node);
}
