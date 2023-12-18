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
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        dfs(root, 0, flag);
        return flag;
    }
    
    int abs(int x) {
        return (x < 0) ? -x : x;
    }
    
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    
    int dfs(TreeNode* root, int depth, bool& flag) {
        if (root == NULL) return depth;
        int ldepth = dfs(root->left, depth + 1, flag);
        int rdepth = dfs(root->right, depth + 1, flag);
        if (abs(ldepth - rdepth) > 1) flag = false;
        return max(ldepth, rdepth);
    }
};