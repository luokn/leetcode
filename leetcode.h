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
    int val = 0;
    ListNode *next = nullptr;

    explicit ListNode(int val) : val(val) {}
};

struct TreeNode {
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

namespace utils {

template <typename Fn> void foreach (ListNode *n, Fn && fn) {
    while (n != nullptr) {
        fn(n->val);
        n = n->next;
    }
}

template <typename T = int, typename TIterable = std::initializer_list<T>>
ListNode *make_nodes(TIterable &&iter) {
    auto it = std::begin(iter);
    auto end = std::end(iter);
    if (it == end) {
        return nullptr;
    }
    auto *first = new ListNode(*it++);
    for (ListNode *cur = first; it != end; ++it, cur = cur->next) {
        cur->next = new ListNode(static_cast<int>(*it));
    }
    return first;
}

inline void del_nodes(ListNode *n) {
    for (ListNode *next; n != nullptr; n = next) {
        next = n->next;
        delete n;
    }
}

inline void print_nodes(ListNode *n) {
    if (n == nullptr) {
        std::cout << "[]" << std::endl;
        return;
    }
    while (n->next != nullptr) {
        std::cout << "[" << n->val << "] -> ";
        n = n->next;
    }
    std::cout << "[" << n->val << "]" << std::endl;
}

inline TreeNode *make_tree(const int v, TreeNode *ln = nullptr,
                           TreeNode *rn = nullptr) {
    return new TreeNode{v, ln, rn};
    ;
}

inline void delete_tree(TreeNode *n) {
    if (n == nullptr) {
        return;
    }
    delete_tree(n->left);
    delete_tree(n->right);
    delete n;
}

template <typename TIterable> void print(TIterable &&iter) {
    auto it = std::begin(iter);
    auto end = std::end(iter);
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

inline void print(std::ostream &out, const int it) {
    out << std::setw(4) << it;
}

inline void print(std::ostream &out, const bool it) {
    out << std::setw(4) << (it ? "O" : "X");
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
    auto it = vec.cbegin();
    auto end = vec.cend();
    out << "[";
    if (it != end) {
        print(out, *it);
        ++it;
        while (it != end) {
            out << ",";
            print(out, *it);
            ++it;
        }
    }
    out << "]" << std::endl;
    return out;
}

template <typename T>
void operator<<(std::ostream &out, const std::vector<std::vector<T>> &mat) {
    for (auto &&vec : mat) {
        for (auto &&v : vec) {
            print(out, v);
        }
        out << std::endl;
    }
}

} // namespace utils