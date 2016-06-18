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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        helper(root, result);
        return result[k - 1];
    }
    
    void helper(TreeNode* root,vector<int>& result){
        if(!root)
            return;
        helper(root->left,result);
        result.push_back(root->val);
        helper(root->right,result);
    }
};