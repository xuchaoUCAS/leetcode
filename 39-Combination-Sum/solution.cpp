class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        helper(candidates, target, temp, result, 0);
        return result;
    }
    
    void helper(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& result, int begin){
        if(!target)
            result.push_back(temp);
        for(int i = begin;i < candidates.size() && target >= candidates[i];++i){
            temp.push_back(candidates[i]);
            helper(candidates, target - candidates[i], temp, result, i);
            temp.pop_back();
        }
    }
};