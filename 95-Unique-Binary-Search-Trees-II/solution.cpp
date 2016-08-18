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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n == 0)
            return result;
        return genTree(1, n);
    }
    
    vector<TreeNode*> genTree(int start, int end){
        vector<TreeNode*> result;
        if(start > end){
            result.push_back(NULL);
            return result;
        }
        
        for(int i = start;i <= end;++i){
            vector<TreeNode*> left = genTree(start, i - 1);
            vector<TreeNode*> right = genTree(i + 1, end);
            
            for(TreeNode* l : left)
                for(TreeNode* r : right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
        }
        return result;
    }
};