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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        merge(root1, root2);
        return root1;
    }

private:
    void merge(TreeNode* cur1, TreeNode* cur2) {
        cur1->val += cur2->val;
        
        if (cur1->left == nullptr) {
            if (cur2->left != nullptr) {
                cur1->left = cur2->left;
            }
        } else {
            if (cur2->left != nullptr) {
                merge(cur1->left, cur2->left);
            }
        }
        
        if (cur1->right == nullptr) {
            if (cur2->right != nullptr) {
                cur1->right = cur2->right;
            }
        } else {
            if (cur2->right != nullptr) {
                merge(cur1->right, cur2->right);
            }
        }
    }
};