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
    int minDiffInBST(TreeNode* root) {
        int pre = -1;
        int ans = 1000000;
        dfs(root, pre, ans);
        return ans;
    }

private:
    void dfs(TreeNode* cur, int& pre, int& ans) {
        if (cur == nullptr) return;
        dfs(cur->left, pre, ans);
        if (pre != -1) {
            ans = min(ans, cur->val - pre);
        }
        pre = cur->val;
        dfs(cur->right, pre, ans);
    }
};