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
        vector<int> result(10,0);
        if(!root)
            return result;
        vector<int> lr = help(root->left);
        vector<int> rr = help(root->right);
        result[0] = max(lr[0], lr[1]) + max(rr[0], rr[1]);
        result[1] = root->val + lr[0] + rr[0];
        return result;
    }
};