class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return n ? nums[0] : 0;
        return max(robb(nums, 0, n -2), robb(nums, 1, n - 1));
    }
    int robb(vector<int>& nums, int l, int r){
        int pre = 0, prepre = 0;
        for(int i = l;i <= r;++i){
            int curr = max(prepre + nums[i], pre);
            prepre = pre;
            pre = curr;
        }
        return pre;
    }
};