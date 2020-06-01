#pragma once
#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
public:
	struct AcNode {
		bool is_end;
		AcNode* fail;
		const string* str;
		map<char, AcNode*> next;

		explicit AcNode(const bool end = false, AcNode* fail = nullptr, const string* str = nullptr) : is_end(end),
			fail(fail),
			str(str) {}
	};

	vector<int> findSubstring(string s, vector<string>& words) {
		set<string> word_set;
		for (const auto& word : words) {
			if (word.empty())
				continue;
			word_set.insert(word);
		}

		const auto ac_root = make_ac_tree(word_set);

		vector<const string*> indices;
		auto ptr = ac_root;
		auto offset = 0;
		while (offset < s.length()) {
			if (const auto& next = ptr->next.find(s[offset]); next != ptr->next.end()) {
				ptr = next->second;
				++offset;
			} else if (ptr->is_end) {
				indices.push_back(ptr->str);
				ptr = ac_root;
			} else {
				ptr = ptr->fail;
				++offset;
			}
		}
		if (ptr->is_end) {
			indices.push_back(ptr->str);
		}
		delete_ac_tree(ac_root);
		return vector<int>{1, 2, 3};
	}

	static AcNode* make_ac_tree(const set<string>& words) {
		const auto root = new AcNode();
		for (const auto& word : words) {
			auto ptr = root;
			uint16_t deep = 1;
			for (auto ch : word) {
				if (const auto& it = ptr->next.find(ch); it != ptr->next.end()) {
					ptr = it->second;
				} else {
					ptr = ptr->next[ch] = new AcNode();
				}
				++deep;
			}
			ptr->is_end = true;
			ptr->str = &word;
		}

		root->fail = root;
		queue<AcNode*> que;
		for (const auto& pair : root->next) {
			que.push(pair.second);
			pair.second->fail = root;
		}

		while (!que.empty()) {
			auto head = que.front();
			que.pop();
			for (const auto& [ch, node] : head->next) {
				auto fail = head->fail->next.find(ch);
				if (fail == head->fail->next.end()) {
					node->fail = root;
				} else {
					node->fail = fail->second;
				}
				que.push(node);
			}
		}

		return root;
	}

	static void delete_ac_tree(AcNode* tree) {
		if (tree == nullptr)
			return;
		for (auto&& pair : tree->next) {
			delete_ac_tree(pair.second);
		}
		delete tree;
	}
};

inline void test() {
	string s("barfoothefoobarman");
	vector<string> words{ "foo", "bar" };
	Solution solution;
	const auto res = solution.findSubstring(s, words);
	cout << res << endl;
}
