/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int res = 0;
        dfs(root, 1, res);
        return res;
    }

private:
    void dfs(Node* cur, int depth, int& res) {
        if (cur == nullptr) return;
        res = max(res, depth);
        for (int i = 0; i < cur->children.size(); i++) {
            dfs(cur->children[i], depth + 1, res);
        }
    }
};