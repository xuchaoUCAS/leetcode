class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        helper(n, temp, result, 1, k);
        return result;
    }
    
    void helper(int target, vector<int>& temp, vector<vector<int>>& result, int begin,int k){
        if(!target && temp.size() == k)
            result.push_back(temp);
        for(int i = begin;i < 10;++i){
            temp.push_back(i);
            helper(target - i, temp, result, i + 1, k);
            temp.pop_back();
        }
    }
};