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
    void sumN(TreeNode* root, int& result, int sum){
        sum = sum * 10 + root->val;
        if(!root->left && !root->right)
            result += sum;
        if(root->left)
            sumN(root->left, result, sum);
        if(root->right)
            sumN(root->right, result, sum);
    }
    
    int sumNumbers(TreeNode* root) {
        int result = 0;
        int sum = 0;
        if(!root)
            return result;
        sumN(root, result, sum);
        return result;
    }
};