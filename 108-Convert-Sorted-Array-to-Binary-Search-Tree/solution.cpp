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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size())
            return NULL;
        else if (nums.size() == 1)
            return new TreeNode(nums[0]);
        int size = nums.size();
        int middle = size / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        vector<int> leftNums(nums.begin(), nums.begin() + middle);
        vector<int> rightNums(nums.begin() + middle + 1, nums.end());
        
        TreeNode* left = sortedArrayToBST(leftNums);
        TreeNode* right = sortedArrayToBST(rightNums);
        root->left = left;
        root->right = right;
        return root;
    }
};