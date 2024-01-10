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
  TreeNode* cur;
  int d;
};

class Solution {
public:
  int amountOfTime(TreeNode* root, int start) {
    map<int, TreeNode*> parentMap;
    TreeNode* startNode = dfs(NULL, root, start, parentMap);

    int ans = 0;
    set<int> visited;
    queue<Placeholder> q;
    visited.insert(start);
    q.push({startNode, 0});
    while (!q.empty()) {
      Placeholder p = q.front();
      q.pop();
      ans = max(ans, p.d);

      vector<TreeNode*> nexts;
      if (parentMap[p.cur->val] != NULL) {
        nexts.push_back(parentMap[p.cur->val]);
      }
      if (p.cur->left != NULL) {
        nexts.push_back(p.cur->left);
      }
      if (p.cur->right != NULL) {
        nexts.push_back(p.cur->right);
      }
      for (auto next : nexts) {
        if (visited.find(next->val) == visited.end()) {
          visited.insert(next->val);
          q.push({next, p.d + 1});
        }
      }
    }
    return ans;
  }

private:
  TreeNode* dfs(
      TreeNode* parent, TreeNode* cur, int start, map<int, TreeNode*>& parentMap) {
    if (cur == NULL) {
      return NULL;
    }
    parentMap[cur->val] = parent;
    TreeNode* leftFind = dfs(cur, cur->left, start, parentMap);
    TreeNode* rightFind = dfs(cur, cur->right, start, parentMap);
    if (cur->val == start) {
      return cur;
    } else if (leftFind != NULL) {
      return leftFind;
    } else if (rightFind != NULL) {
      return rightFind;
    }
    return NULL;
  }
};
