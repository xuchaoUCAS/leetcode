class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> set;
        for(auto n : nums1)
            set.insert(n);
        for(auto n : nums2){
            if(set.find(n) != set.end()){
                set.erase(n);
                result.push_back(n);
            }
                
        }
        return result;
    }
};