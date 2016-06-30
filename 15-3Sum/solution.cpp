class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size();++i){
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum < target)
                    ++l;
                else if(sum > target)
                    --r;
                else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    result.push_back(temp);
                    
                    while(l < r && nums[l] == temp[1])
                        ++l;
                    while(l < r && nums[r] == temp[2])
                        --r;
                }
            }
            
            while(i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
        }
        return result;
    }
    
};