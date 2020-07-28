// https://leetcode-cn.com/problems/print-in-order/

#pragma once

#include <algorithm>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class Foo {
  public:
    Foo() {}

    void first(function<void()> &&fn) {
        fn();
        flags_[0] = true;
        cv_.notify_all();
    }

    void second(function<void()> &&fn) {
        unique_lock<mutex> lock(mtx_);
        cv_.wait(lock, [this] { return flags_[0]; });
        fn();
        flags_[1] = true;
        cv_.notify_all();
    }

    void third(function<void()> &&fn) {
        unique_lock<mutex> lock(mtx_);
        cv_.wait(lock, [this] { return flags_[1]; });
        fn();
    }

  private:
    mutex mtx_;
    condition_variable cv_;
    bool flags_[2]{false, false};
};

inline void test() {
    Foo foo;
    auto one = [] { cout << "one"; };
    auto two = [] { cout << "two"; };
    auto three = [] { cout << "three"; };

    thread thd3([&] { foo.third(three); });
    thread thd1([&] { foo.first(one); });
    thread thd2([&] { foo.second(two); });
    thd3.join();
    thd1.join();
    thd2.join();
}