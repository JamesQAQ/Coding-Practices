class Solution {
public:
  Node* cloneGraph(Node* node) {
    vector<Node*> newNodes = vector<Node*>(101, NULL);
    return cloneNode(node, newNodes);
  }

private:
  Node* cloneNode(Node* cur, vector<Node*>& newNodes) {
    if (cur == NULL) {
      return NULL;
    }
    if (newNodes[cur->val] == NULL) {
      newNodes[cur->val] = new Node(cur->val);
      for (auto neighbor : cur->neighbors) {
        newNodes[cur->val]->neighbors.push_back(
            cloneNode(neighbor, newNodes));
      }
    }
    return newNodes[cur->val];
  }
};
