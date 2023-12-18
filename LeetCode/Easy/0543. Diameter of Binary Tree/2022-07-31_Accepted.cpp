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
    int ans = 0;
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }

private:
    int dfs(TreeNode* cur, int depth, int& ans) {
        if (cur == nullptr) {
            return depth - 1;
        }
        int l = dfs(cur->left, depth + 1, ans);
        int r = dfs(cur->right, depth + 1, ans);
        ans = max(ans, l + r - 2 * depth);
        return max(l, r);
    }
};