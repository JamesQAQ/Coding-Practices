/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define MAX 1000

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* stack[MAX];
        bool one[MAX];
        int top = 0;
        one[top] = false;
        stack[top++] = root;
        int count = 0;
        while (top > 0){
            TreeNode* now = stack[top - 1];
            if (!one[top - 1]){
                one[top - 1] = true;
                if (now->left == NULL)
                    continue;
                one[top] = false;
                stack[top++] = now->left;
            }
            else{
                count++;
                if (count == k)
                    return now->val;
                top--;
                if (now->right == NULL)
                    continue;
                one[top] = false;
                stack[top++] = now->right;
            }
        }
    }
};
