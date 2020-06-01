#include "leetcode.h"

using namespace utils;

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr)
			return head;
		auto target = head;
		auto counter = 0;
		for (auto cursor = head; cursor != nullptr; cursor = cursor->next, ++counter) {
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
	Solution solution;
	const auto nodes = make_nodes({ 1 });
	print_nodes(solution.removeNthFromEnd(nodes, 1));
}

