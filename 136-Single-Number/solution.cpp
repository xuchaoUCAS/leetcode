class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hashTable;
        for(auto n : nums){
            hashTable[n]++;
        }
        for(auto& n : hashTable){
            if(n.second == 1)
                return n.first;
        }
        return 1;
    }
};