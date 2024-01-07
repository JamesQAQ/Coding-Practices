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
public:
  void recoverTree(TreeNode* root) {
    vector<TreeNode*> inorder;
    dfs(root, inorder);
    vector<TreeNode*> sorted = inorder;
    sort(sorted.begin(), sorted.end(), cmp);
    TreeNode* first = NULL;
    for (int i = 0; i < inorder.size(); i++) {
      if (inorder[i]->val != sorted[i]->val) {
        if (first == NULL) {
          first = inorder[i];
        } else {
          swap(first->val, inorder[i]->val);
        }
      }
    }
  }

private:
  void dfs(TreeNode* root, vector<TreeNode*>& inorder) {
    if (root == NULL) {
      return;
    }
    dfs(root->left, inorder);
    inorder.push_back(root);
    dfs(root->right, inorder);
  }

  static bool cmp(TreeNode* i, TreeNode* j) {
    return i->val < j->val;
  }
};
