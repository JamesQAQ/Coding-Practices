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
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    return dfs(cloned, target->val);
  }

private:
  TreeNode* dfs(TreeNode* cur, int val) {
    if (cur == NULL) {
      return NULL;
    }
    if (cur->val == val) {
      return cur;
    }
    TreeNode* ret = dfs(cur->left, val);
    if (ret != NULL) {
      return ret;
    }
    ret = dfs(cur->right, val);
    if (ret != NULL) {
      return ret;
    }
    return NULL;
  }
};
