class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0)
            return 0;
        vector<int> dp = vector<int>(len + 1, 0);
        dp[len] = 1;
        dp[len - 1] = s[len - 1] != '0' ? 1 : 0;
        for(int i = len - 2;i >= 0;--i){
            if(s[i] == '0')
                continue;
            else
                dp[i] = (stoi(s.substr(i, 2)) <= 26) ? dp[i + 1] + dp[i + 2] : dp[i + 1];
        }
        return dp[0];
    }
};