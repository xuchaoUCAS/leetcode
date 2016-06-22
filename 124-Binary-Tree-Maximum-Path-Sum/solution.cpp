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
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        helper(root, result);
        return result;
    }
    
    int helper(TreeNode* root, int& result){
        if(!root)
            return 0;
        int l = max(0, helper(root->left, result));
        int r = max(0, helper(root->right, result));
        result = max(result, l + r + root->val);
        
        return max(l, r) + root->val;
    }
};