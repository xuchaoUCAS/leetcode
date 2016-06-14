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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> temp;
        if(!root)
            return result;
        help(root, sum, temp, result);
        return result;
    }
    void help(TreeNode* root, int sum, vector<int> temp, vector<vector<int>>& result){
        if(!root)
            return;
        if(!root->left && !root->right){
            if(root->val == sum){
                temp.push_back(root->val);
                result.push_back(temp);
            }
        }
        temp.push_back(root->val);
        if(!root->left && root->right)
            help(root->right, sum - root->val, temp, result);
        else if(root->left && !root->right)
            help(root->left, sum - root->val, temp, result);
        else{
            help(root->right, sum - root->val, temp, result);
            help(root->left, sum - root->val, temp, result);
        }
    }
};