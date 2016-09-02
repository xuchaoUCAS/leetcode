class Solution {
public:
    void per(vector<int>& s,int start,vector<vector<int>>& result){
        if(start == s.size())
            result.push_back(s);
        else{
            for(int i = start;i < s.size();++i){
                swap(s[start], s[i]);
                per(s, start + 1, result);
                swap(s[start], s[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        per(nums, 0, result);
        return result;
    }
};