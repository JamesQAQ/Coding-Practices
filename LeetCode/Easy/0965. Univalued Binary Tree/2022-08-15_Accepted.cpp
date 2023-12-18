/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) return true;
        return dfs(root, root->val);
    }

private:
    bool dfs(TreeNode* cur, int v) {
        if (cur == nullptr) return true;
        if (cur->val != v) return false;
        return dfs(cur->left, v) && dfs(cur->right, v);
    }
};