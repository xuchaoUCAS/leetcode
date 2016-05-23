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
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
    
    int dfs(TreeNode* root, int& maxPath){
        if(!root)
            return 0;
        int l = max(0, dfs(root->left, maxPath));
        int r = max(0, dfs(root->right, maxPath));
        maxPath = max(maxPath, l + r + root->val);
        return root->val + max(l, r);
    }
};