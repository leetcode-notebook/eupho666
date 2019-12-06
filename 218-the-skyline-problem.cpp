// the-skyline-problem.cpp : 此文件包含 "main"
// 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    multiset<pair<int,int>> nodes;
    vector<vector<int>> res;
    for (auto &n : buildings) {
      nodes.insert(make_pair(n[0], -n[2]));
      nodes.insert(make_pair(n[1], n[2]));

    }

    vector<int> last_node{0, 0};
    multiset<int> heights({0});
    for (auto &n : nodes) {
      if (n.second < 0) {
        heights.insert(-n.second);
      } else {
        heights.erase(heights.find(n.second));
      }

      int max_height = *heights.rbegin();
      if (max_height != last_node[1]) {
        last_node[0] = n.first;
        last_node[1] = max_height;
        res.push_back(last_node);
      }
    }
    return res;
  }
};

int main() { std::cout << "Hello World!\n"; }