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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while (curr || !s.empty()) {
        if (curr) {
            s.push(curr);
            curr = curr -> left;
        }
        else {
            curr = s.top();
            s.pop();
            nodes.push_back(curr -> val);
            curr = curr -> right;
        }
    }
    return nodes;
    }
};