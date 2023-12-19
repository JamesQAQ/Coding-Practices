/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define MAX 4000

class BSTIterator {
private:
    TreeNode* stack[MAX];
    bool one[MAX];
    int top, val;
public:
    BSTIterator(TreeNode *root) {
        if (root == NULL){
            top = 0;
        }
        else{
            stack[0] = root;
            one[0] = false;
            top = 1;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        while (top > 0){
            TreeNode *now = stack[top - 1];
            if (!one[top - 1]){
                one[top - 1] = true;
                if (now->left){
                    stack[top] = now->left;
                    one[top] = false;
                    top++;
                }
            }
            else{
                val = now->val;
                top--;
                if (now->right){
                    stack[top] = now->right;
                    one[top] = false;
                    top++;
                }
                return true;
            }
        }
        return false;
    }

    /** @return the next smallest number */
    int next() {
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
