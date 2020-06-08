#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

struct ListNode {
    int value;
    ListNode *next;
    explicit ListNode(const int value) : value(value), next(nullptr) {}
};

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(const int value)
        : value(value), left(nullptr), right(nullptr) {}
};

namespace utils {

template <typename Fn> void foreach (ListNode *node, Fn && fn) {
    while (node != nullptr) {
        fn(node->value);
        node = node->next;
    }
}

template <typename T = int, typename TIterable = std::initializer_list<T>>
ListNode *make_nodes(TIterable &&values) {
    auto iter = std::begin(values);
    auto end = std::end(values);
    if (iter == end)
        return nullptr;
    ListNode *first = new ListNode(*iter++);
    for (ListNode *cur = first; iter != end; ++iter, cur = cur->next) {
        cur->next = new ListNode(static_cast<int>(*iter));
    }
    return first;
}

inline void del_nodes(ListNode *node) {
    for (ListNode *next; node != nullptr; node = next) {
        next = node->next;
        delete node;
    }
}

inline void print_nodes(ListNode *node) {
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

inline TreeNode *make_tree(const int value, TreeNode *left = nullptr,
                           TreeNode *right = nullptr) {
    const auto node = new TreeNode(value);
    node->left = left;
    node->right = right;
    return node;
}

inline void delete_tree(TreeNode *node) {
    if (node == nullptr)
        return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template <class TIterable> void iterable_print(const TIterable &iterable) {
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

inline void item_print(std::ostream &out, const int item) {
    out << std::setw(4) << item;
}

inline void item_print(std::ostream &out, const bool item) {
    out << std::setw(4) << (item ? "O" : "X");
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vector) {
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
    return out;
}

template <typename T>
void operator<<(std::ostream &out, const std::vector<std::vector<T>> &matrix) {
    for (auto &&vec : matrix) {
        for (auto &&val : vec) {
            item_print(out, val);
        }
        out << std::endl;
    }
}

} // namespace utils