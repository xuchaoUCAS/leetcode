class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;
        for(int i = 0;i < nums.size();++i){
            map[nums[i]] = i;
        }
        for(int i = 0;i < nums.size();++i){
            if(map[target - nums[i]]){
                result.push_back(i);
                result.push_back(map[target - nums[i]]);\
                return result;
            }
        }
        return result;
    }
};