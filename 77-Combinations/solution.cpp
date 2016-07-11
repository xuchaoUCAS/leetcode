class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        helper(n, k, temp, result, 1);
        return result;
    }
    
    void helper(int n,int k, vector<int>& temp, vector<vector<int>>& result, int begin){
        if(temp.size() == k)
            result.push_back(temp);
        for(int i = begin;i <= n; ++i){
            temp.push_back(i);
            helper(n, k, temp, result, i + 1);
            temp.pop_back();
        }
    }
};