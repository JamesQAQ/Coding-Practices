class Solution {
private:
  vector<Node*> tails;

public:
  Node* connect(Node* root) {
    tails = vector<Node*>(6000, NULL);
    dfs(0, root);
    return root;
  }

private:
  void dfs(int depth, Node* cur) {
    if (cur == NULL) {
      return;
    }
    if (tails[depth] != NULL) {
      tails[depth]->next = cur;
    }
    tails[depth] = cur;
    dfs(depth + 1, cur->left);
    dfs(depth + 1, cur->right);
  }
};
