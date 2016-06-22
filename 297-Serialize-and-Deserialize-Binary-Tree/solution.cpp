/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "# ";
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        ans += to_string(root->val) + " ";
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(temp->left){
                ans += to_string(temp->left->val) + " ";
                q.push(temp->left);
            }
            else
                ans += "# ";
            if(temp->right){
                ans += to_string(temp->right->val) + " ";
                q.push(temp->right);
            }
            else
                ans += "# ";
            q.pop();
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;
        ss >> s;
        if(s == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q; 
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(temp){
                string left ,right;
                ss >> left;
                ss >> right;
                if(left == "#")
                    temp->left = NULL;
                else{
                    temp->left =  new TreeNode(stoi(left));
                }
                if(right == "#")
                    temp->right = NULL;
                else{
                    temp->right = new TreeNode(stoi(right));
                }
                q.push(temp->left);
                q.push(temp->right);
            }
            q.pop();
        }
        return root; 
    }

};
