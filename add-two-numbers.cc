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

		if (flow != 0) ptr->next = new ListNode(flow);
		return res;
	}
};

int main(int argc, char* argv[]) {
	const auto a = new ListNode(2);
	a->next = new ListNode(4);
	a->next->next = new ListNode(3);

	const auto b = new ListNode(5);
	b->next = new ListNode(6);
	b->next->next = new ListNode(4);
	b->next->next->next = new ListNode(2);

	Solution solution;
	const auto res = solution.addTwoNumbers(a, b);
	for (auto ptr = res; ptr != nullptr; ptr = ptr->next) {
		cout << ptr->value << " ";
	}
}
