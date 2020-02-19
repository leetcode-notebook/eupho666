/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root){
            queue<TreeNode*> q;
            TreeNode* node;
            q.push(root);

            while(!q.empty()){
                int sz = q.size();
                vector<int> temp;
                for(int i = 0;i < sz;++i){
                    node = q.front();
                    q.pop();
                    temp.push_back(node->val);
                    if(node->left)  q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                res.push_back(temp);
            }

        }
        return res;
        

    }
};