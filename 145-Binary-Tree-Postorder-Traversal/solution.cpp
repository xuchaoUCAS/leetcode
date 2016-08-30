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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postorderTraversal(root, v);
        return v;
    }
    
    void postorderTraversal(TreeNode* root, vector<int>& v){
        if(!root)
            return;
        postorderTraversal(root->left, v);
        postorderTraversal(root->right, v);
        v.push_back(root->val);
    }
};