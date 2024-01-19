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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> idxMap;
    for (int i = 0; i < inorder.size(); i++) {
      idxMap[inorder[i]] = i;
    }
    int ptr = postorder.size() - 1;
    return buildNode(ptr, 0, postorder.size() - 1, postorder, idxMap);
  }

private:
  TreeNode* buildNode(
      int& ptr,
      int left,
      int right,
      vector<int>& postorder,
      unordered_map<int, int>& idxMap) {
    if (ptr == -1
        || left > idxMap[postorder[ptr]] || idxMap[postorder[ptr]] > right) {
      return NULL;
    }
    int pos = idxMap[postorder[ptr]];
    TreeNode* root = new TreeNode(postorder[ptr--]);
    root->right = buildNode(ptr, pos + 1, right, postorder, idxMap);
    root->left =  buildNode(ptr, left, pos - 1, postorder, idxMap);
    return root;
  }
};
