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
    bool isSymmetric(TreeNode* root) {
        return dfs(root, root);
    }
    
    bool dfs(TreeNode* l, TreeNode* r) {
        if (l == NULL || r == NULL) {
            return l == NULL && r == NULL;
        }
        if (l->val != r->val) return false;
        bool flag = true;
        flag &= dfs(l->left, r->right);
        flag &= dfs(l->right, r->left);
        return flag;
    }
};