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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        dfs(root1, res1);
        dfs(root2, res2);
        for (int i = 0; i < min(res1.size(), res2.size()); i++) {
            if (res1[i] != res2[i]) {
                 return false;
            }
        }
        return res1.size() == res2.size();
    }

private:
    void dfs(TreeNode* cur, vector<int>& res) {
        if (cur == nullptr) return;
        if (cur->left == nullptr && cur->right == nullptr) {
            res.push_back(cur->val);
        } else {
            dfs(cur->left, res);
            dfs(cur->right, res);
        }
}
};