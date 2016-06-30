class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = INT_MIN;
        int closest = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size();++i){
            int t = target - nums[i];
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(abs(sum - t) < closest){
                    closest = abs(sum - t);
                    result = sum + nums[i];
                }
                if(sum < t)
                    ++l;
                else if(sum > t)
                    --r;
                else
                    return target;
            }
        }
        return result;
    }
};