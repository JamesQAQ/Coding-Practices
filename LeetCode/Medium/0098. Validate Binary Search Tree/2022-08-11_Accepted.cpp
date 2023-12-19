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
    TreeNode* pre;
    
public:
    bool isValidBST(TreeNode* root) {
        pre = nullptr;
        return dfs(root);
    }

private:
    bool dfs(TreeNode* cur) {
        if (cur == nullptr) return true;
        if (!dfs(cur->left)) return false;
        if (pre != nullptr && pre->val >= cur->val) return false;
        pre = cur;
        if (!dfs(cur->right)) return false;
        return true;
    }
};