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
    vector<int> val;
    vector<int> count;
    int maxCount;
    
public:
    vector<int> findMode(TreeNode* root) {
        val.clear();
        count.clear();
        maxCount = 0;
        dfs(root);
        vector<int> ans;
        for (int i = 0; i < count.size(); i++) {
            if (count[i] == maxCount) {
                ans.push_back(val[i]);
            }
        }
        return ans;
    }
    
private:
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        if (val.size() == 0 || root->val != val[val.size() - 1]) {
            val.push_back(root->val);
            count.push_back(0);
        }
        count[count.size() - 1]++;
        maxCount = max(maxCount, count[count.size() - 1]);
        dfs(root->right);
    }
};