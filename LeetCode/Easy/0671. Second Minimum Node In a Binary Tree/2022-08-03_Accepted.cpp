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
    int findSecondMinimumValue(TreeNode* root) {
        int ans = -1;
        dfs(root, root->val, ans);
        return ans;
    }

private:
    void dfs(TreeNode* cur, int val, int& ans) {
        if (cur == nullptr) return;
        if (cur->val != val) {
            if (ans == -1 || cur->val < ans) ans = cur->val;
            return;
        }
        dfs(cur->left, val, ans);
        dfs(cur->right, val, ans);
    }
};