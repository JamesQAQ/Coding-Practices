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
    bool findTarget(TreeNode* root, int k) {
        bool ans = false;
        traversal(root, k, root, ans);
        return ans;
    }

private:
    void traversal(TreeNode* cur, int k, TreeNode* root, bool& ans) {
        if (ans || cur == nullptr) return;
        if (find(root, k - cur->val, cur)) {
            ans = true;
            return;
        }
        traversal(cur->left, k, root, ans);
        traversal(cur->right, k, root, ans);
    }
    
    bool find(TreeNode* cur, int val, TreeNode* pre) {
        if (cur == nullptr) return false;
        if (cur != pre && cur->val == val) return true;
        if (cur->val > val) return find(cur->left, val, pre);
        if (cur->val < val) return find(cur->right, val, pre);
        return false;
    }
};