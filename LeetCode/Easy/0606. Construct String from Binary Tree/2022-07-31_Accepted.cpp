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
    string tree2str(TreeNode* root) {
        string ans = "";
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(TreeNode* cur, string& ans) {
        ans += to_string(cur->val);
        if (cur->left != nullptr) {
            ans += "(";
            dfs(cur->left, ans);
            ans += ")";
        }
        if (cur->right != nullptr) {
            if (cur->left == nullptr) ans += "()";
            ans += "(";
            dfs(cur->right, ans);
            ans += ")";
        }
    }
};