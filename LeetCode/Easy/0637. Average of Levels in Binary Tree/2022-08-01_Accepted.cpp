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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<long long> sum;
        vector<int> cnt;
        dfs(root, 0, sum, cnt);
        vector<double> ans;
        for (int i = 0; i < sum.size(); i++) {
            ans.push_back((double)sum[i] / cnt[i]);
        }
        return ans;
    }

private:
    void dfs(TreeNode* cur, int depth, vector<long long>& sum, vector<int>& cnt) {
        if (cur == nullptr) return;
        while (depth >= sum.size()) {
            sum.push_back(0);
            cnt.push_back(0);
        }
        sum[depth] += cur->val;
        cnt[depth]++;
        dfs(cur->left, depth + 1, sum, cnt);
        dfs(cur->right, depth + 1, sum, cnt);
    }
};