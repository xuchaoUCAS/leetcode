class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newLength = 0;
        for(auto n : nums){
            if(newLength < 2 || n > nums[newLength - 2])
                nums[newLength++] = n;
        }
        return newLength;
        
    }
};