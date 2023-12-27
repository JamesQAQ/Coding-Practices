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
  int sumRootToLeaf(TreeNode* root) {
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
  }

private:
  void dfs(TreeNode* cur, int previousNum, int& ans) {
    if (cur == NULL) {
      return;
    }
    int currentNum = 2 * previousNum + cur->val;
    if (cur->left == NULL && cur->right == NULL) {
      ans += currentNum;
    } else {
      dfs(cur->left, currentNum, ans);
      dfs(cur->right, currentNum, ans);
    }
  }
};
