/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_visited;
        vector<TreeNode*> q_visited;
        find(root, p, p_visited);
        find(root, q, q_visited);
        TreeNode* ans = NULL;
        for (int i = 0; i < p_visited.size() && i < q_visited.size(); i++) {
            if (p_visited[i] == q_visited[i]) ans = p_visited[i];
        }
        return ans;
    }
private:
    void find(TreeNode* root, TreeNode* x, vector<TreeNode*>& visited) {
        if (root == NULL) return;
        visited.push_back(root);
        if (root->val == x->val) {
            return;
        }
        if (x->val < root->val) {
            find(root->left, x, visited);
        } else {
            find(root->right, x, visited);
        }
    }
};