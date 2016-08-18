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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder,  0, inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& pre, int ps, int pe, vector<int>& in, int is, int ie){
        if(ps > pe)
            return NULL;
        TreeNode* root = new TreeNode(pre[ps]);
        
        int rootIndex = 0;
        for(int i = is;i <= ie;++i){
            if(in[i] == root->val){
                rootIndex = i;
                break;
            }
        }
        
        root->left = buildTree(pre, ps + 1, ps + rootIndex - is, in, is, rootIndex - 1);
        root->right = buildTree(pre, pe - ie + rootIndex + 1, pe, in, rootIndex + 1, ie);
        
        return root;
    }
};