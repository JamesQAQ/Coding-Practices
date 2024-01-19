// This is NOT for `Follow-up`.
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
private:
  TreeNode* tail;

public:
  void flatten(TreeNode* root) {
    tail = NULL;
    dfs(root);
  }

private:
  void dfs(TreeNode* cur) {
    if (cur == NULL) {
      return;
    }
    if (tail != NULL) {
      tail->left = NULL;
      tail->right = cur;
    }
    tail = cur;
    TreeNode* right = cur->right;
    dfs(cur->left);
    dfs(right);
  }
};
