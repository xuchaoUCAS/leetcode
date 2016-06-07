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
    void binaryTree(TreeNode* root, vector<string>& v,string s){
        if(!root->left && !root->right){
            s += to_string(root->val);
            v.push_back(s);
            return;
        }
        s = s + to_string(root->val) + "->";
        if(root->left)
            binaryTree(root->left, v, s);
        if(root->right)
            binaryTree(root->right, v, s);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string s;
        if(!root)
            return result;
        binaryTree(root, result, s);
        return result;
    }
};