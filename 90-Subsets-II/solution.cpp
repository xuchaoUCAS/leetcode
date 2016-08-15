class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        helper(nums, result, temp, 0);
        return result;
    }
    
    void helper(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int start){
        result.push_back(temp);
        for(int i = start;i < nums.size();++i){
            if(i == start || nums[i] != nums[i - 1]){
                temp.push_back(nums[i]);
                helper(nums, result, temp, i + 1);
                temp.pop_back();
            }
        }
    }
};