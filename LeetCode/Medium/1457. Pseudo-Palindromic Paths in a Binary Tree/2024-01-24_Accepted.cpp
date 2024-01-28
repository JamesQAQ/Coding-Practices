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
  int pseudoPalindromicPaths (TreeNode* root) {
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
  }

private:
  void dfs(TreeNode* root, int val, int& ans) {
    val ^= (1 << root->val);
    if (root->left == NULL && root->right == NULL) {
      if (countBits(val) <= 1) {
        ans++;
      }
      return;
    }
    if (root->left != NULL) {
      dfs(root->left, val, ans);
    }
    if (root->right != NULL) {
      dfs(root->right, val, ans);
    }
  }

  int countBits(int x) {
    int count = 0;
    while (x) {
      x -= (x & -x);
      count++;
    }
    return count;
  }
};
