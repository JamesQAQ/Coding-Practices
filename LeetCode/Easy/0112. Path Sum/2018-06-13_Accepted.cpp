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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        bool flag = false;
        dfs(root, 0, sum, flag);
        return flag;
    }
    
    void dfs(TreeNode* root, int sum, int target, bool& flag) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            if (sum + root->val == target) flag = true;
            return;
        }
        dfs(root->left, sum + root->val, target, flag);
        dfs(root->right, sum + root->val, target, flag);
    }
};