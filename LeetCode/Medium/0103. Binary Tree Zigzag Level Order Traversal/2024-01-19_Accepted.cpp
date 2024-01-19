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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    dfs(0, root, result);
    for (int i = 1; i < result.size(); i += 2) {
      reverse(result[i].begin(), result[i].end());
    }
    return result;
  }

private:
  void dfs(int depth, TreeNode* cur, vector<vector<int>>& result) {
    if (cur == NULL) {
      return;
    }
    if (depth >= result.size()) {
      result.push_back(vector<int>());
    }
    dfs(depth + 1, cur->left, result);
    result[depth].push_back(cur->val);
    dfs(depth + 1, cur->right, result);
  }
};