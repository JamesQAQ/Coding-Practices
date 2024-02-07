class Solution {
public:
  int sumNumbers(TreeNode* root) {
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
  }

private:
  void dfs(TreeNode* cur, int val, int& ans) {
    if (cur == NULL) {
      return;
    }
    int newVal = val * 10 + cur->val;
    if (cur->left == NULL && cur->right == NULL) {
      ans += newVal ;
      return;
    }
    dfs(cur->left, newVal, ans);
    dfs(cur->right, newVal, ans);
  }
};
