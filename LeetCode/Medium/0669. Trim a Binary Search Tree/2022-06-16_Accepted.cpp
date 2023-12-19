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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // Find a legal root.
        while (root != nullptr && !(low <= root->val && root->val <= high)) {
            if (root->val < low) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        if (root == nullptr) {
            return nullptr;
        }
        
        // Trim Left.
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                break;
            }
            if (cur->left->val < low) {
                TreeNode* ptr = cur->left->right;
                while (ptr != nullptr) {
                    if (ptr->val >= low) {
                        break;
                    }
                    ptr = ptr->right;
                }
                cur->left = ptr;
            }
            cur = cur->left;
        }
        
        // Trim right.
        cur = root;
        while (cur != nullptr) {
            if (cur->right == nullptr) {
                break;
            }
            if (cur->right->val > high) {
                TreeNode* ptr = cur->right->left;
                while (ptr != nullptr) {
                    if (ptr->val <= high) {
                        break;
                    }
                    ptr = ptr->left;
                }
                cur->right = ptr;
            }
            cur = cur->right;
        }
        return root;
    }
};
