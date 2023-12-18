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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        dfs(root, low, high, ans);
        return ans;
    }

private:
    void dfs(TreeNode* cur, int low, int high, int& ans) {
        if (cur == nullptr) return;
        if (low <= cur->val && cur->val <= high) ans += cur->val;
        dfs(cur->left, low, high, ans);
        dfs(cur->right, low, high, ans);
    }
};