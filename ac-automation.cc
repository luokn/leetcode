#include "./leetcode.h"

using namespace std;
using namespace utils;

class Solution {
public:
	// AC自动机
	struct AcNode {
		uint16_t deep;
		bool is_end;
		AcNode* fail;
		map<char, AcNode*> next;

		explicit AcNode(const uint16_t deep, const bool end = false, AcNode* fail = nullptr) : deep(deep), is_end(end),
			fail(fail) {}
	};

	vector<int> findSubstring(const string& s, vector<string>& words) {
		set<string> word_set;
		for (const auto& word : words) {
			if (word.empty())
				continue;
			word_set.insert(word);
		}

		const auto ac_root = make_ac_tree(word_set);

		vector<int> indices;
		auto ptr = ac_root;
		auto offset = 0;
		while (offset < s.length()) {
			if (const auto& next = ptr->next.find(s[offset]); next != ptr->next.end()) {
				ptr = next->second;
				++offset;
			} else if (ptr->is_end) {
				indices.push_back(offset - ptr->deep);
				ptr = ac_root;
			} else {
				ptr = ptr->fail;
				++offset;
			}
		}
		if (ptr->is_end) {
			indices.push_back(s.length() - ptr->deep);
		}
		delete_ac_tree(ac_root);
		return indices;
	}

	static AcNode* make_ac_tree(const set<string>& words) {
		const auto root = new AcNode(0);
		for (const auto& word : words) {
			auto ptr = root;
			uint16_t deep = 1;
			for (auto ch : word) {
				if (const auto& it = ptr->next.find(ch); it != ptr->next.end()) {
					ptr = it->second;
				} else {
					ptr = ptr->next[ch] = new AcNode(deep);
				}
				++deep;
			}
			ptr->is_end = true;
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


int main(int argc, char* argv[]) {
	string s("barfoothefoobarman");
	vector<string> words{ "foo", "bar" };
	Solution solution;
	const auto res = solution.findSubstring(s, words);
	cout << res;
}
