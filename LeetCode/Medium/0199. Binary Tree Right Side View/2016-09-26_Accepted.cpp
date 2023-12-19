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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root != NULL)
            dfs(root, res, 1);
        return res;
    }
private:
    void dfs(TreeNode* now, vector<int> &res, int dfn) {
        if (dfn > res.size())
            res.push_back(now->val);
        else
            res[dfn - 1] = now->val;
        if (now->left != NULL)
            dfs(now->left, res, dfn + 1);
        if (now->right != NULL)
            dfs(now->right, res, dfn + 1);
    }
};
