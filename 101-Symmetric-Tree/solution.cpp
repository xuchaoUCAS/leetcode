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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        else
            return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if((left == right) && (left == NULL))
            return true;
        else if((left && !right) || (!left && right))
            return false;
        else if(left->val == right->val)
            return isSymmetric(left->right, right->left) && isSymmetric(left->left, right->right);
        else
            return false;
    }
};