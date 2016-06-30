class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0;i < nums.size();++i){
            int t1 = target - nums[i];
            for(int j = i + 1;j < nums.size();++j){
                int t2 = t1 - nums[j];
                int l = j + 1, r = nums.size() - 1;
                while(l < r){
                    int sum = nums[l] + nums[r];
                    if(sum < t2)
                        ++l;
                    else if(sum > t2)
                        --r;
                    else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        result.push_back(temp);
                        
                        while(l < r && nums[l] == temp[2])
                            ++l;
                        while(l < r && nums[r] == temp[3])
                            --r;
                    }   
                }
                while(j + 1 < nums.size() && nums[j + 1] == nums[j])
                    ++j;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
        }
        return result;
    }
};