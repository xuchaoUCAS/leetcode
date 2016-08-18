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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post, int is, int ie, int ps, int pe){
        if(is > ie)
            return NULL;
        
        TreeNode* root = new TreeNode(post[pe]);
        int rootIndex = 0;
        for(int i = is; i <= ie; ++i){
            if(in[i] == root->val){
                rootIndex = i;
                break;
            }
        }
        
        root->left = buildTree(in, post, is, rootIndex - 1, ps, ps + rootIndex - is - 1);
        root->right = buildTree(in, post, rootIndex + 1, ie, ps + rootIndex - is, pe - 1);
        
        return root;
    }
    
};