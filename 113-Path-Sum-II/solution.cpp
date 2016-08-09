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
        temp.push_back(root->val);
        if(!root->left && !root->right && root->val == sum){
            result.push_back(temp);
        }
        else{
            help(root->right, sum - root->val, temp, result);
            help(root->left, sum - root->val, temp, result);
        }
    }
};