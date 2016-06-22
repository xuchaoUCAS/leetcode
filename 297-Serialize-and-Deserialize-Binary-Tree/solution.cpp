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
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;
        ss >> s;
        if(s == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        return deserialize(ss, root);
    }
private:
    void serialize(TreeNode* root, stringstream& ss){
        queue<TreeNode*> q;
        q.push(root);
        if(!root){
            ss << "# ";
            return;
        }
        else
            ss << root->val << " ";
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(temp){
                q.push(temp->left);
                q.push(temp->right);
                temp->left ? ss << temp->left->val << " " : ss << "# ";
                temp->right ? ss << temp->right->val << " " : ss << "# "; 
            }
            q.pop();
        }
    }
    
    TreeNode* deserialize(stringstream& ss, TreeNode* root){
        queue<TreeNode*> q;
        string left,right;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(temp){
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