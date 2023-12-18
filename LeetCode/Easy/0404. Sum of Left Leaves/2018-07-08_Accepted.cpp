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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = 0;
        dfs(root, false, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, bool left, int& ans) {
        if (root == NULL) return;
        if (left && root->left == NULL && root->right == NULL) {
            ans += root->val;
            return;
        }
        dfs(root->left, true, ans);
        dfs(root->right, false, ans);
    }
};