class Solution {
public:
    bool hasSwap(vector<int>s, int start, int end){
        while(start < end){
            if(s[start] == s[end])
                return false;
            start++;
        }
        return true;
    }


    void per(vector<int> s, int start, vector<vector<int>>& result){
        if(start == s.size()){
            result.push_back(s);
            return;
        }
        else{
            for(int i = start;i < s.size();++i){
                if(i != start && s[i] == s[start])
                    continue;
                swap(s[start], s[i]);
                per(s, start + 1, result);
                //swap(s[start], s[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        per(nums, 0, result);
        return result;
    }
};