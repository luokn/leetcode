#include "leetcode.h"

using namespace std;

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        switch (lists.size()) {
            case 0: return nullptr;
            case 1: return lists.front();
            case 2: return merge_2_lists(lists.front(), lists.back());
            default: {
                size_t             len = lists.size();
                vector<ListNode *> buf((lists.size() + 1) / 2);
                for (size_t idx = 0;;) {
                    while (idx < len / 2) {
                        buf[idx] = merge_2_lists(lists[2 * idx], lists[2 * idx + 1]);
                        ++idx;
                    }
                    if (len % 2) { buf[idx] = lists[len - 1]; }
                    len = (len + 1) / 2;
                    if (len == 2) { return merge_2_lists(buf[0], buf[1]); }
                    for (uint32_t i = 0; i < len; ++i) { lists[i] = buf[i]; }
                }
            }
        }
    }

    static ListNode *merge_2_lists(ListNode *ln, ListNode *rn) {
        ListNode  node(0);
        ListNode *cur = &node;
        while (ln != nullptr && rn != nullptr) {
            if (ln->value < rn->value) {
                cur->next = ln;
                cur       = cur->next;
                ln        = ln->next;
            } else {
                cur->next = rn;
                cur       = cur->next;
                rn        = rn->next;
            }
        }

        while (ln != nullptr) {
            cur->next = ln;
            cur       = cur->next;
            ln        = ln->next;
        }

        while (rn != nullptr) {
            cur->next = rn;
            cur       = cur->next;
            rn        = rn->next;
        }
        return node.next;
    }
};

int main(int argc, char const *argv[]) {
    const auto         list1 = utils::make_nodes({1, 4, 5});
    const auto         list2 = utils::make_nodes({2, 4, 6});
    const auto         list3 = utils::make_nodes({1, 2});
    vector<ListNode *> nodes{list1, list2, list3};
    Solution           solution;
    const auto         res = solution.mergeKLists(nodes);
    auto               ptr = res;
    while (ptr != nullptr) {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }

    utils::del_nodes(res);
}
