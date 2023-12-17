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
    int maxPathSum(TreeNode* root) {
        int ans = -2147483648;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode* root, int& ans) {
        if (root == NULL) {
            return 0;
        }
        int l_max_path = dfs(root->left, ans);
        int r_max_path = dfs(root->right, ans);
        int max_path = root->val + max(max(l_max_path, r_max_path), max(0, l_max_path + r_max_path));
        if (max_path > ans) ans = max_path;
        return max(max(0, root->val), max(root->val + l_max_path, root->val + r_max_path));
    }
    
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
};