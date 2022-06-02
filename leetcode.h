#pragma once

#include <bits/stdc++.h>

struct ListNode {
    int       value = 0;
    ListNode *next  = nullptr;
    explicit ListNode(int val) : value(val) {}
};

struct TreeNode {
    int       value = 0;
    TreeNode *left  = nullptr;
    TreeNode *right = nullptr;
};

namespace utils {

template <typename Fn>
void foreach (ListNode *n, Fn && fn) {
    while (n != nullptr) {
        fn(n->value);
        n = n->next;
    }
}

template <typename T = int, typename TIterable = std::initializer_list<T>>
ListNode *make_nodes(TIterable &&iterable) {
    auto end  = std::end(iterable);
    auto iter = std::begin(iterable);
    if (iter == end) {
        return nullptr;
    }
    auto *head = new ListNode(*iter++);
    for (ListNode *p = head; iter != end; ++iter, p = p->next) {
        p->next = new ListNode(static_cast<int>(*iter));
    }
    return head;
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
        std::cout << "[" << n->value << "] -> ";
        n = n->next;
    }
    std::cout << "[" << n->value << "]" << std::endl;
}

inline TreeNode *make_tree(const int v, TreeNode *ln = nullptr, TreeNode *rn = nullptr) {
    return new TreeNode{v, ln, rn};
}

inline void del_tree(TreeNode *n) {
    if (n == nullptr) {
        return;
    }
    del_tree(n->left);
    del_tree(n->right);
    delete n;
}

template <typename TIterable>
void print(TIterable &&iterable) {
    auto end  = std::end(iterable);
    auto iter = std::begin(iterable);
    std::cout << "[";
    if (iter != end) {
        std::cout << *iter;
        ++iter;
    }
    while (iter != end) {
        std::cout << ", " << *iter;
        ++iter;
    }
    std::cout << "]";
}

inline void print(std::ostream &out, const int it) {
    out << std::setw(4) << it;
}

inline void print(std::ostream &out, const bool it) {
    out << std::setw(4) << (it ? "O" : "X");
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
    print(vec);
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

}  // namespace utils