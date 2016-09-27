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
    int rob(TreeNode* root) {
        vector<int> result = help(root);
        return max(result[0], result[1]);
    }
    vector<int> help(TreeNode* root){
        vector<int> result(2,0);
        if(!root)
            return result;
        vector<int> l = help(root->left);
        vector<int> r = help(root->right);
        result[0] = max(l[0], l[1]) + max(r[0], r[1]);
        result[1] = root->val + l[0] + r[0];
        return result;
    }
};