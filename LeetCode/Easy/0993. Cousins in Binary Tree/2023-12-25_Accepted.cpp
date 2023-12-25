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

struct FindValue {
  int depth;
  TreeNode *parent;
};

class Solution {
public:
  bool isCousins(TreeNode* root, int x, int y) {
    FindValue findx = dfs(root, NULL, 0, x);
    FindValue findy = dfs(root, NULL, 0, y);
    return findx.depth == findy.depth && findx.parent != findy.parent;
  }

private:
  FindValue dfs(TreeNode* cur, TreeNode* parent, int depth, int x) {
    if (cur == NULL) {
      return {-1, NULL};
    }
    if (cur->val == x) {
      return {depth, parent};
    }
    FindValue f = dfs(cur->left, cur, depth + 1, x);
    if (f.depth != -1) {
      return f;
    }
    f = dfs(cur->right, cur, depth + 1, x);
    if (f.depth != -1) {
      return f;
    }
    return {-1, NULL};
  }
};
