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
    int L = 13;
    int R = 17;
    int MOD = 1000000007;
    int BASE = 10001;
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        long long val = dfs(subRoot);
        dfs2(root, val, ans);
        return ans;
    }

private:
    long long dfs(TreeNode* cur) {
        if (cur == nullptr) return 0;
        return (cur->val + BASE + L * dfs(cur->left) + R * dfs(cur->right)) % MOD;
    }
    
    long long dfs2(TreeNode* cur, long long val, bool& ans) {
        if (cur == nullptr) return 0;
        long long v = (cur->val + BASE + L * dfs2(cur->left, val, ans) + R * dfs2(cur->right, val, ans)) % MOD;
        if (v == val) ans = true;
        return v;
    }
};