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
        queue<TreeNode*> q;
        string result;
        q.push(root);
        result += to_string(root->val) + " ";
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(temp){
                q.push(temp->left);
                q.push(temp->right);
                temp->left ? result += to_string(temp->left->val) + " " : result += "# ";
                temp->right ? result += to_string(temp->right->val) + " " : result += "# ";
            }
            q.pop();
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;
        ss >> s;
        if(s == "#")
            return  NULL;
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(temp){
                string left, right;
                ss >> left;
                ss >> right;
                left == "#" ? temp->left = NULL : temp->left = new TreeNode(stoi(left));
                right == "#" ? temp->right = NULL : temp->right = new TreeNode(stoi(right));
                q.push(temp->left);
                q.push(temp->right);
            }
            q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));