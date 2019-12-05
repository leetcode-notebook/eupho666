/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
public:
    struct Node{
        int val;
        int count;
        shared_ptr<Node> left;
        shared_ptr<Node> right;
        Node(int val):val(val), count(0){}
    };
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        shared_ptr<Node> root;
        for(int i = nums.size() - 1; i >= 0; i--){
            root = insert(root, nums[i], i, &res);
        }
        return res;
    }
    shared_ptr<Node> insert(shared_ptr<Node> root, int num, int index, vector<int> *resptr){
        if(!root){
            return make_shared<Node>(num);
        }
        if(num <= root->val){
            root->count++;
            root->left = insert(root->left, num, index, resptr);
        }else{
            (*resptr)[index] += root->count + 1;
            root->right = insert(root->right, num, index, resptr);
        }
        return root;

    }
};
// @lc code=end

