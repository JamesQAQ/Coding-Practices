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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        
        int ans = 2147483647;
        dfs(root, 1, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int depth, int& ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            if (depth < ans) ans = depth;
            return;
        }
        dfs(root->left, depth + 1, ans);
        dfs(root->right, depth + 1, ans);
    }
};