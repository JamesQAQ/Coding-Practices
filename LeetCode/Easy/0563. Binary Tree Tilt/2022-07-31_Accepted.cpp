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
    int findTilt(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode* cur, int& ans) {
        if (cur == nullptr) return 0;
        int l = dfs(cur->left, ans);
        int r = dfs(cur->right, ans);
        ans += abs(r - l);
        return cur->val + l + r;
    }
};