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
    int pathSum(TreeNode* root, int sum) {
        map<int, int> sum_set;
        int ans = 0;
        dfs(root, 0, sum, sum_set, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int cur_sum, int sum, map<int, int>& sum_set, int& ans) {
        if (root == NULL) return;
        if (root->val == sum) ans++;
        int target = sum - (cur_sum + root->val);
        if (sum_set.find(target) != sum_set.end()) {
            ans += sum_set[target];
        }
        int val = -cur_sum;
        if (sum_set.find(val) != sum_set.end()) {
            sum_set[val]++;
        } else {
            sum_set[val] = 1;
        }
        
        dfs(root->left, cur_sum + root->val, sum, sum_set, ans);
        dfs(root->right, cur_sum + root->val, sum, sum_set, ans);
        
        sum_set[val]--;
    }
};