class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> result;
        for(int i = 0;i < nums1.size();++i)
            ++map[nums1[i]];
        for(auto n : nums2){
            if(map[n] > 0){
                result.push_back(n);
                --map[n];
            }
        }
        return result;
    }
};