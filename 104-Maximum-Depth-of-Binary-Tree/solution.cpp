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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        helper(root, depth);
        return depth;
    }
    
    void helper(TreeNode* root,int& depth){
        if(!root){
            depth = 0;
            return;
        }
        int l,r;
        helper(root->left, l);
        helper(root->right, r);
        depth = l > r ? l : r;
        ++depth;
    }
};