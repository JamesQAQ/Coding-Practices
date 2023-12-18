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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return dfs(0, nums.size() - 1, nums);
    }
    
    TreeNode* dfs(int l, int r, vector<int>& nums) {
        if (l > r) return NULL;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (l == r) return root;
        root->left = dfs(l, mid - 1, nums);
        root->right = dfs(mid + 1, r, nums);
        return root;
    }
};