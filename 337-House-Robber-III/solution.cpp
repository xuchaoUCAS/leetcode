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
        pair<int, int> result = robb(root);
        return max(result.first, result.second);
    }
    pair<int, int> robb(TreeNode* root){
        if(!root)
            return make_pair(0, 0);
        pair<int, int> l = robb(root->left);
        pair<int, int> r = robb(root->right);
        int f = max(l.first, l.second) + max(r.first, r.second);
        int s = root->val + l.first + r.first;
        return make_pair(f, s);
    }
};