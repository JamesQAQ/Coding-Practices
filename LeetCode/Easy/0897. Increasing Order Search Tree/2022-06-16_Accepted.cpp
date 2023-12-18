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
    TreeNode* ans;
    TreeNode* cur;
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        ans = cur = nullptr;
        dfs(root);
        return ans;
    }
    
private:
    void dfs(TreeNode* ptr) {
        if (ptr == nullptr) {
            return;
        }
        
        dfs(ptr->left);
        
        TreeNode* right = ptr->right;
        if (cur == nullptr) {
            ans = ptr;
            cur = ptr;
        } else {
            cur = cur->right = ptr;
        }
        cur->left = cur->right = nullptr;
        
        dfs(right);
    }
};