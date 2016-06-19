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
    bool isSym(TreeNode* left,TreeNode* right){
        if(!left && !right)
            return true;
        if(!left || !right)
            return false;
        if(left->val == right->val)
            return isSym(left->right, right->left) && isSym(left->left, right->right);
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSym(root->left, root->right);
    }
};