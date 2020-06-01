#include "leetcode.h"


using namespace std;

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		switch (lists.size()) {
		case 0:
			return nullptr;
		case 1:
			return lists.front();
		case 2:
			return merge2Lists(lists.front(), lists.back());
		default:
			uint32_t size = lists.size();
			vector<ListNode*> buf((lists.size() + 1) / 2);
			while (true) {
				uint32_t idx = 0;

				while (idx < size / 2) {
					buf[idx] = merge2Lists(lists[2 * idx], lists[2 * idx + 1]);
					++idx;
				}

				if (size % 2)
					buf[idx] = lists[size - 1];

				size = (size + 1) / 2;

				if (size == 2)
					return merge2Lists(buf[0], buf[1]);

				for (uint32_t i = 0; i < size; ++i) {
					lists[i] = buf[i];
				}
			}
		}
	}

	ListNode* merge2Lists(ListNode* l, ListNode* r) {
		ListNode node(0);
		auto ptr = &node;
		while (l != nullptr && r != nullptr) {
			if (l->value < r->value) {
				ptr->next = l;
				ptr = ptr->next;
				l = l->next;
			} else {
				ptr->next = r;
				ptr = ptr->next;
				r = r->next;
			}
		}

		while (l != nullptr) {
			ptr->next = l;
			ptr = ptr->next;
			l = l->next;
		}

		while (r != nullptr) {
			ptr->next = r;
			ptr = ptr->next;
			r = r->next;
		}
		return node.next;
	}
};


inline void test() {
	const auto list1 = utils::make_nodes({ 1,4,5 });
	const auto list2 = utils::make_nodes({ 2,4,6 });
	const auto list3 = utils::make_nodes({ 1,2 });
	vector<ListNode*> nodes{ list1, list2, list3 };
	Solution solution;
	const auto res = solution.mergeKLists(nodes);
	auto ptr = res;
	while (ptr != nullptr) {
		cout << ptr->value << " ";
		ptr = ptr->next;
	}

	utils::del_nodes(res);
}
