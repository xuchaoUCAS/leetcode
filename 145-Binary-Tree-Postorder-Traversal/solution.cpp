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
        vector<int> nodes;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        TreeNode* last = NULL;
        while (curr || !s.empty()) {
            if (curr) {
                s.push(curr);
                curr = curr -> left;
            }
            else {
                TreeNode* topNode = s.top();
                if (topNode -> right && last != topNode -> right)
                    curr = topNode -> right;
                else {
                    nodes.push_back(topNode -> val);
                    last = topNode;
                    s.pop();
                }
            }
        }
        return nodes;
    }
};