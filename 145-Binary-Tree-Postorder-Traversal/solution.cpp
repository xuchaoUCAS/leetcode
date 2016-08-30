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
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* curr = root, *last = NULL;
        while(curr || !s.empty()){
            if(curr){
                s.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* temp = s.top();
                if(temp->right && last != temp->right)
                    curr = temp->right;
                else{
                    result.push_back(temp->val);
                    last = temp;
                    s.pop();
                }
            }
        }
        return result;
    }
};