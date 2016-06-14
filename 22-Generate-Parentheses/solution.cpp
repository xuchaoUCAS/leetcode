class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp;
        helper(result, temp, n, 0);
        return result;
    }
    
    void helper(vector<string>& result, string temp, int n ,int m){
        if(n == 0 && m == 0){
            result.push_back(temp);
            return;
        }
        if(n > 0)
            helper(result, temp + "(", n - 1, m + 1);
        if(m > 0)
            helper(result, temp + ")", n , m - 1);
    }
};