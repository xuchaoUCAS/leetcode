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
        stack<TreeNode*> toVisit;
        TreeNode* curNode = root;
        TreeNode* lastNode = NULL;
        while (curNode || !toVisit.empty()) {
            if (curNode) {
                toVisit.push(curNode);
                curNode = curNode -> left;
            }
            else {
                TreeNode* topNode = toVisit.top();
                if (topNode -> right && lastNode != topNode -> right)
                    curNode = topNode -> right;
                else {
                    nodes.push_back(topNode -> val);
                    lastNode = topNode;
                    toVisit.pop();
                }
            }
        }
        return nodes;
    }
};