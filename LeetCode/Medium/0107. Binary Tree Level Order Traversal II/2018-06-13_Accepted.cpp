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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        for (int i = 0; i < res.size() / 2; i++) {
            vector<int> tmp = res[i];
            res[i] = res[res.size() - 1 - i];
            res[res.size() - 1 - i] = tmp;
        }
        return res;
    }
    
    void dfs(TreeNode* root, int depth, vector<vector<int>> &res) {
        if (root == NULL) return;
        
        if (depth >= res.size()) {
            vector<int> tmp;
            res.push_back(tmp);
        }
        
        dfs(root->left, depth + 1, res);
        res[depth].push_back(root->val);
        dfs(root->right, depth + 1, res);
    }
};