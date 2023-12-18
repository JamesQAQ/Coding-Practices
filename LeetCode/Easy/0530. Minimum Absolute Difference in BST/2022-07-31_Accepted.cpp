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
    int getMinimumDifference(TreeNode* root) {
        int ans = -1;
        int pre = -1;
        dfs(root, ans, pre);
        return ans;
    }

private:
    void dfs(TreeNode* cur, int& ans, int& pre) {
        if (cur == nullptr) return;
        dfs(cur->left, ans, pre);
        if (pre != -1) {
            int val = cur->val - pre;
            if (ans == -1 || val < ans) {
                ans = val;
            }
        }
        pre = cur->val;
        dfs(cur->right, ans, pre);
    }
};