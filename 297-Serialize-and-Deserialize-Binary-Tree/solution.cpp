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
    void serialize(TreeNode * root, stringstream &ss){
        if(!root){
            ss<<"# ";
        }else{
            ss<<root->val<<" ";
            serialize(root->left, ss);
            serialize(root->right, ss);
        }
    }
    TreeNode *deserialize(stringstream &ss){
        string s;
        ss>>s;
        if(s=="#"){
            return NULL;
        }else{
            TreeNode *node = new TreeNode(stoi(s));
            node->left = deserialize(ss);
            node->right = deserialize(ss);
            return node;
        }
    }
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
        return deserialize(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));