// https://leetcode-cn.com/problems/building-h2o/

#pragma once

#include <condition_variable>
#include <functional>
#include <iostream>
#include <queue>
#include <thread>

using namespace std;

class H2O {
  public:
    H2O() {}

    void hydrogen(function<void()> &&release_hydrogen) {

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        release_hydrogen();
    }

    void oxygen(function<void()> &&release_oxygen) {

        // releaseOxygen() outputs "O". Do not change or remove this line.
        release_oxygen();
    }
};

inline void test() {
    auto release_hydrogen = [] { cout << "H"; };
    auto release_oxygen = [] { cout << "O"; };

    H2O h2o;
    thread h_thread([&] { h2o.hydrogen(release_hydrogen); });
    thread o_thread([&] { h2o.oxygen(release_oxygen); });
    h_thread.join();
    o_thread.join();
}