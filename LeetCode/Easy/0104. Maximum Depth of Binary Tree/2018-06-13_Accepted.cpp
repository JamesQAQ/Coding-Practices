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
    int maxDepth(TreeNode* root) {
        return dfs(root, 1);
    }
    
    int dfs(TreeNode* root, int depth) {
        if (root == NULL) return depth - 1;
        int max_depth = depth;
        max_depth = max(max_depth, dfs(root->left, depth + 1));
        max_depth = max(max_depth, dfs(root->right, depth + 1));
        return max_depth;
    }
    
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
};