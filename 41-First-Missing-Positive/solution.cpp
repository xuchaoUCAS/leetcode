class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto n : nums)
            map[n]++;
        int i = 1;
        while(i){
            if(!map[i])
                return i;
            ++i;
        }
        return i;
    }
};