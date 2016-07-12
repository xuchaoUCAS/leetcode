class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dis = 0;
        for(int i = 0;i < nums.size();++i){
            if(dis < i)
                return false;
            int steps = nums[i] + i;
            dis = max(dis, steps);
        }
        return true;
    }
};