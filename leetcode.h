#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <chrono>
#include <sstream>
#include <fstream>
#include <random>
#include <utility>
#include <iterator>
#include <algorithm>
#include <list>
#include <vector>
#include <array>
#include <map>
#include <numeric>
#include <deque>
#include <functional>
#include <memory>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <cassert>
#include <iomanip>

struct ListNode {
	int value;
	ListNode* next;
	explicit ListNode(const int v) : value(v), next(nullptr) {}
};

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	explicit TreeNode(const int v) : value(v), left(nullptr), right(nullptr) {}
};

namespace utils {
	using namespace std;

	inline void foreach_nodes(ListNode* node, const std::function<void(int)>& fn) {
		while (node != nullptr) {
			fn(node->value);
			node = node->next;
		}
	}
	inline ListNode* make_nodes(const std::vector<int>& values) {
		if (values.empty()) return nullptr;
		auto it = values.cbegin();
		const auto first = new ListNode(*it++);
		for (auto cur = first; it != values.cend(); ++it, cur = cur->next) {
			cur->next = new ListNode(*it);
		}
		return first;
	}

	inline ListNode* make_nodes(const std::initializer_list<int>& values) {
		if (values.size() == 0) return nullptr;
		auto it = values.begin();
		const auto first = new ListNode(*it++);
		for (auto cur = first; it != values.end(); ++it, cur = cur->next) {
			cur->next = new ListNode(*it);
		}
		return first;
	}

	inline void free_nodes(ListNode* node) {
		for (ListNode* next; node != nullptr; node = next) {
			next = node->next;
			delete node;
		}
	}

	inline void print_nodes(ListNode* node) {
		if (node == nullptr) {
			std::cout << "[]" << std::endl;
			return;
		}
		while (node->next != nullptr) {
			std::cout << "[" << node->value << "] -> ";
			node = node->next;
		}
		std::cout << "[" << node->value << "]" << std::endl;
	}

	inline TreeNode* make_tree(const int value, TreeNode* left = nullptr, TreeNode* right = nullptr) {
		const auto node = new TreeNode(value);
		node->left = left;
		node->right = right;
		return node;
	}

	inline void delete_tree(TreeNode* node) {
		if (node == nullptr) return;
		delete_tree(node->left);
		delete_tree(node->right);
		delete node;
	}

	template<class TIterable>
	void iterable_print(const TIterable& iterable) {
		auto it = std::begin(iterable);
		auto end = std::end(iterable);
		std::cout << "[";
		if (it != end) {
			std::cout << *it;
			++it;
		}
		while (it != end) {
			std::cout << ", " << *it;
			++it;
		}
		std::cout << "]" << std::endl;
	}

	inline void item_print(ostream& out, const int item) {
		out << std::setw(4) << item;
	}

	inline void item_print(ostream& out, const bool item) {
		out << std::setw(4) << (item ? "O" : "X");
	}

	template<typename T>
	void operator<<(ostream& out, const std::vector<T>& vector) {
		auto it = vector.cbegin();
		out << "[";
		if (it != vector.cend()) {
			item_print(out, *it);
			++it;
			while (it != vector.cend()) {
				out << ",";
				item_print(out, *it);
				++it;
			}
		}
		out << "]" << std::endl;
	}

	template<typename T>
	void operator<<(ostream& out, const vector<vector<T>>& matrix) {
		for (auto&& vec : matrix) {
			for (auto&& val : vec) {
				item_print(out, val);
			}
			out << std::endl;
		}
	}

}