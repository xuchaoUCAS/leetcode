class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        helper(nums, result, temp, 0);
        return result;
    }
    
    void helper(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int start){
        result.push_back(temp);
        for(int i = start;i < nums.size();++i){
            temp.push_back(nums[i]);
            helper(nums, result, temp, i + 1);
            temp.pop_back();
        }
    }
};