/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using std::to_string;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, string path, vector<string>& ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path + to_string(root->val));
            return;
        }
        path += to_string(root->val) + "->";
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }
};