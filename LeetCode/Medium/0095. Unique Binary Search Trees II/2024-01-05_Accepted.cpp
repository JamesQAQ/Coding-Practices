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
  vector<TreeNode*> generateTrees(int n) {
    return dfs(1, n);
  }

private:
  vector<TreeNode*> dfs(int left, int right) {
    if (right < left) {
      return {NULL};
    }
    vector<TreeNode*> result;
    for (int i = left; i <= right; i++) {
      for (auto lRoot : dfs(left, i - 1)) {
        for (auto rRoot: dfs(i + 1, right)) {
          result.push_back(new TreeNode(i, lRoot, rRoot));
        }
      }
    }
    return result;
  }
};
