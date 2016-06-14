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
    void flatten(TreeNode* root) {
    while(root){
        if(root->left && root->right){
            TreeNode* temp = root->left;
            while(temp->right)
                temp = temp->right;
            temp->right = root->right;
        }
        if(root->left)
            root->right = root->left;
        root->left = NULL;
        root = root->right;
    }
    }
};