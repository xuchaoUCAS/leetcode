class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r = nums.size() - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        
        int rindex = l;
        l = 0, r = nums.size();
        while(l <= r){
            int mid = (l + r) / 2;
            int realmid = (mid + rindex) % nums.size();
            if(nums[realmid] == target)
                return realmid;
            if(nums[realmid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};