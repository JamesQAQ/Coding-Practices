/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
    
private:
    void dfs(Node* root, int level, vector<vector<int>>& ans) {
        if (root == NULL) return;
        if (ans.size() == level) {
            vector<int> tmp;
            ans.push_back(tmp);
        }
        ans[level].push_back(root->val);
        for (int i = 0; i < root->children.size(); i++) {
            Node* child = root->children[i];
            dfs(child, level + 1, ans);
        }
    }
};