class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return 0;
        vector<int> dp = vector<int>(len, 0);
        dp[0] = 1;
        int maxd = -1, result = dp[0];
        for(int i = 0;i < len;++i){
            for(int j = 0;j < i;++j){
                if(nums[j] < nums[i])
                    maxd = max(maxd, dp[j]);
            }
            dp[i] = maxd > 0 ? maxd + 1 : 1;
            result = max(result, dp[i]);
            maxd = -1;
        }
        return result;
    }
};