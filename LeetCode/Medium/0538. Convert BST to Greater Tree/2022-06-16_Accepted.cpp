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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }

private:
    void dfs(TreeNode* ptr, int& sum) {
        if (ptr == nullptr) {
            return;
        }
        
        dfs(ptr->right, sum);
        sum += ptr->val;
        ptr->val = sum;
        dfs(ptr->left, sum);
    }
};