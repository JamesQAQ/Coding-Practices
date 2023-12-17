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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        else if (p != NULL && q != NULL) {
            if (p->val != q->val)
                return false;
            bool same = true;
            if (p->left != NULL && q->left != NULL)
                same &= isSameTree(p->left, q->left);
            else if (!(p->left == NULL && q->left == NULL))
                return false;
            if (p->right != NULL && q->right != NULL)
                same &= isSameTree(p->right, q->right);
            else if (!(p->right == NULL && q->right == NULL))
                return false;
            return same;
        }
        else
            return false;
    }
};
