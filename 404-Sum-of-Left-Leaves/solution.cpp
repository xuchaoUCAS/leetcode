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
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        helper(root, result);
        return result;
    }
    void helper(TreeNode* root,int& result){
        if(!root)
            return;
        if(root->left && !root->left->left && !root->left->right)
            result += root->left->val;
        helper(root->left, result);
        helper(root->right, result);
    }
};