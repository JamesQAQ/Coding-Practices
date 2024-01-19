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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> idxMap;
    for (int i = 0; i < inorder.size(); i++) {
      idxMap[inorder[i]] = i;
    }
    int ptr = 0;
    return buildNode(ptr, 0, preorder.size() - 1, preorder, idxMap);
  }

private:
  TreeNode* buildNode(
      int& ptr,
      int left,
      int right,
      vector<int>& preorder,
      unordered_map<int, int>& idxMap) {
    if (ptr == preorder.size()
        || left > idxMap[preorder[ptr]] || idxMap[preorder[ptr]] > right) {
      return NULL;
    }
    int pos = idxMap[preorder[ptr]];
    return new TreeNode(
        preorder[ptr++],
        buildNode(ptr, left, pos - 1, preorder, idxMap),
        buildNode(ptr, pos + 1, right, preorder, idxMap));
  }
};
