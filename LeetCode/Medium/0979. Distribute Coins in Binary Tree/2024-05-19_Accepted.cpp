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
  int distributeCoins(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
  }

  int dfs(TreeNode* cur, int& ans) {
    if (cur == NULL) {
      return 0;
    }
    int leftDelta = dfs(cur->left, ans);
    int rightDelta = dfs(cur->right, ans);
    ans += abs(leftDelta) + abs(rightDelta);
    int delta = leftDelta + rightDelta + cur->val - 1;
    return delta;
  }
};