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
    bool isValidBST(TreeNode* root) {
        return valid(root, NULL, NULL);
    }
    
    bool valid(TreeNode* root, TreeNode* min, TreeNode* max){
        if(!root)
            return true;
        if(min && min->val >= root->val || max && root->val >= max->val)
            return false;
        return valid(root->left, min, root) && valid(root->right, root, max);
    }
};