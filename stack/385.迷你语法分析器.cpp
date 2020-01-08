/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation

 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  NestedInteger deserialize(string s) {
    stack<NestedInteger *> stk;
    string numStr;
    for (char &c : s) {
      if (c == '[') {
        NestedInteger *res = new NestedInteger();
        stk.push(res);
      } else if (c == '-' || isdigit(c)) {
        if (stk.empty())
          return NestedInteger(stoi(s));
        else
          numStr.push_back(c);
      } else if (c == ',') {
        if (!numStr.empty()) {
          stk.top()->add(NestedInteger(stoi(numStr)));
          numStr = "";
        }
      } else {
        if (!numStr.empty()) {
          stk.top()->add(NestedInteger(stoi(numStr)));
          numStr = "";
        }
        NestedInteger *res = stk.top();
        stk.pop();
        if (stk.empty()) {
          return *res;
        } else {
          stk.top()->add(*res);
        }
      }
    }
    return NestedInteger();
  }
};
// @lc code=end
