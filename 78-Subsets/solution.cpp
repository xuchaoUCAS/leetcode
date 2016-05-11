class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int total = pow(2, len);
        vector<vector<int>> result(total, vector<int>());
        for(int i = 0;i < len;++i)
            for(int j = 0;j < total;++j){
                if((j >> i) & 1)
                    result[j].push_back(nums[i]);
            }
        return result;
    }
};