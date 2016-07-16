class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        int newLength = 0;
        int dup = 1;
        for(int i = 0;i < length;++i){
            if(i > 0 && nums[i] == nums[i - 1])
                dup++;
            if(i > 0 && nums[i] != nums[i - 1])
                dup = 1;
            if(i == 0 || dup <= 2)
                nums[newLength++] = nums[i];
        }
        return newLength;
    }
};