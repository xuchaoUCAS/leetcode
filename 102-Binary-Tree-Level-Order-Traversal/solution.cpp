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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> t_vector;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp ==  NULL){
                result.push_back(t_vector);
                t_vector.resize(0);
                if(q.size() > 0)
                    q.push(NULL);
            }
            else{
                t_vector.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return result;
    }
};