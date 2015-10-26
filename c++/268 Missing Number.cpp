class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        sort(nums.begin(), nums.end());
        for(vector<int>::iterator iter = nums.begin(); iter!= nums.end(); iter++){
            if(*iter != i)
                return i;
            i++;
        }
        return i;
    }
};