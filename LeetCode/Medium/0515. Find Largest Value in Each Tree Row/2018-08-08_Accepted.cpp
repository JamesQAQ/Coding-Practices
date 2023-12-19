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
    vector<int> largestValues(TreeNode* root) {
        vector<int> maxVal;
        dfs(root, 0, maxVal);
        return maxVal;
    }

private:
    void dfs(TreeNode* root, int level, vector<int>& maxVal) {
        if (root == NULL) return;
        if (level >= maxVal.size()) {
            maxVal.push_back(root->val);
        } else {
            maxVal[level] = max(maxVal[level], root->val);
        }
        dfs(root->left, level + 1, maxVal);
        dfs(root->right, level + 1, maxVal);
    }
};