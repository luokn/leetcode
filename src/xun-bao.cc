// https://leetcode-cn.com/problems/xun-bao/

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimalSteps(const vector<string>& maze) {
        const size_t           H = maze.size(), W = maze.front().size();
        pair<int, int>         sloc, tloc;
        vector<pair<int, int>> mloc, oloc;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                switch (maze[i][j]) {
                    case 'M': mloc.emplace_back(i, j); break;
                    case 'O': oloc.emplace_back(i, j); break;
                    case 'S': sloc = make_pair(i, j); break;
                    case 'T': tloc = make_pair(i, j); break;
                    default: break;
                }
            }
        }

        return -1;
    }

    int minimalSteps(const vector<string> maze, const pair<int, int>& f, const pair<int, int>& t) { return -1; }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << solution.minimalSteps({"S#O", "M..", "M.T"}) << endl; // -1
    cout << solution.minimalSteps({"S#O", "M.T", "M.."}) << endl; // 17
}