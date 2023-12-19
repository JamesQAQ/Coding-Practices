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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        vector<int> path;
        path.push_back(root->val);
        dfs(root, root->val, sum, path, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int curSum, int targetSum, vector<int> path, vector<vector<int>>& ans) {
        if (root->left == NULL && root->right == NULL) {
            if (curSum == targetSum) {
                ans.push_back(path);
            }
            return;
        }
        if (root->left != NULL) {
            path.push_back(root->left->val);
            dfs(root->left, curSum + root->left->val, targetSum, path, ans);
            path.pop_back();
        }
        if (root->right != NULL) {
            path.push_back(root->right->val);
            dfs(root->right, curSum + root->right->val, targetSum, path, ans);
            path.pop_back();
        }
    }
};