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
        if(!root || (!root->left && !root->right))
            return true;
        return isValid(root->left, root->val, 0) && isValid(root->right, root->val, 1) && isValidBST(root->left) && isValidBST(root->right);
    }
    
    bool isValid(TreeNode* root, int val, int pan){
        if(!root)
            return true;
        bool l = isValid(root->left, val, pan);
        bool r = isValid(root->right, val, pan);
        return l && r && (pan ? root->val > val : root->val < val);
    }
};