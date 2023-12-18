/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MAX 100

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> ans;
        if (root == NULL)
            return ans;
        TreeNode* stack[MAX];
        bool one[MAX];
        int top = 0;
        ans.push_back(root->val);
        one[top] = false;
        stack[top++] = root;
        while (top > 0){
            TreeNode* now = stack[top - 1];
            if (!one[top - 1]){
                one[top - 1] = true;
                if (now->left == NULL)
                    continue;
                ans.push_back(now->left->val);
                one[top] = false;
                stack[top++] = now->left;
            }
            else{
                top--;
                if (now->right == NULL)
                    continue;
                ans.push_back(now->right->val);
                one[top] = false;
                stack[top++] = now->right;
            }
        }
        return ans;
    }
};
