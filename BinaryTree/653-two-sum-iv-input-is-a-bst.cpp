/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* findNum(TreeNode* root, int n){
        if(root == nullptr || root->val == n)
            return root;
        if(n > root->val)
            return findNum(root->right, n);

        else return findNum(root->left, n);
    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k);
    }
    bool dfs(TreeNode* root,TreeNode* node, int k){
        if(node == nullptr)
            return false;
        TreeNode* n2 = findNum(root, k - node->val);
        if(n2 != nullptr && node != n2 )
            return true;
        return dfs(root, node->left, k) || dfs(root, node->right, k);
    }
};