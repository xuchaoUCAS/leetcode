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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        else
            return 1 + Max(maxDepth(root->left), maxDepth(root->right));
    }
private:
    int Max(int a, int b){
        return a > b ? a: b;
    }
};