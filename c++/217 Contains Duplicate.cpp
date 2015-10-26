class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() < 2)
            return false;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};