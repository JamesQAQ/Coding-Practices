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
struct Placeholder {
  int minVal;
  int maxVal;

  void update(Placeholder other) {
    minVal = min(minVal, other.minVal);
    maxVal = max(maxVal, other.maxVal);
  }
};

class Solution {
public:
  int maxAncestorDiff(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
  }

private:
  Placeholder dfs(TreeNode* cur, int& ans) {
    if (cur->left == cur->right) {
      return {cur->val, cur->val};
    }
    Placeholder p = {100001, -1};
    if (cur->left != NULL) {
      p.update(dfs(cur->left, ans));
    }
    if (cur->right != NULL) {
      p.update(dfs(cur->right, ans));
    }
    ans = max(ans, max(abs(cur->val - p.minVal), abs(cur->val - p.maxVal)));
    p.update({cur->val, cur->val});
    return p;
  }
};
