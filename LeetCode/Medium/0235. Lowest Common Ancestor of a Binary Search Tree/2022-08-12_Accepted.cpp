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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return search(root, p->val, q->val);
    }

private:
    TreeNode* search(TreeNode* cur, int p, int q) {
        if (cur == nullptr) return nullptr;
        if (p < cur->val && q < cur->val) return search(cur->left, p, q);
        if (p > cur->val && q > cur->val) return search(cur->right, p, q);
        return cur;
    }
};