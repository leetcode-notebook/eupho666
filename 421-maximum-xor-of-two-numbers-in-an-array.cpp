/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution
{
public:
    struct Node
    {
        Node *one;
        Node *zero;
        Node() : one(nullptr), zero(nullptr) {}
    };

    Node *CreateTree(const vector<int> &nums)
    {
        Node *root = new Node();
        for (auto &num : nums)
        {
            Node *n = root;

            for (int i = 30; i >= 0; --i)
            {
                bool isOne = (num >> i) & 1;
                if (isOne)
                {
                    if (!n->one)
                    {
                        n->one = new Node();
                    }
                    n = n->one;
                }
                else
                {
                    if (!n->zero)
                    {
                        n->zero = new Node();
                    }
                    n = n->zero;
                }
            }
        }
        return root;
    }

    int search(Node *root, int num)
    {
        Node *n = root;
        int res = 0;
        for (int i = 30; i >= 0; --i)
        {
            bool isOne = (num >> i) & 1;
            if (isOne)
            {
                if (n->zero)
                {
                    res |= (1 << i);
                    n = n->zero;
                }
                else if (n->one)
                {
                    n = n->one;
                }
            }
            else
            {
                if (n->one)
                {
                    res |= (1 << i);
                    n = n->one;
                }
                else if (n->zero)
                {
                    n = n->zero;
                }
            }
        }
        return res;
    }

    int findMaximumXOR(vector<int> &nums)
    {
        int res = INT_MIN;
        Node *root = CreateTree(nums);
        for (auto &num : nums)
        {
            res = max(res, search(root, num));
        }
        return res;
    }
};
// @lc code=end
