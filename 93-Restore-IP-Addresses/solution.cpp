class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        helper(s, "", result ,0);
        return result;
    }
    
    void helper(string s, string temp, vector<string>& result, int n){
        if(n == 4){
            if(s.length() == 0)
                result.push_back(temp.substr(0, temp.length() - 1));
            return;
        }
        
        for(int i = 1;i <= 3;++i){
            if(s.length() < i)
                continue;
            int val = stoi(s.substr(0, i));
            if(val > 255 || i != to_string(val).length())
                continue;
            helper(s.substr(i), temp + s.substr(0, i) + ".", result, n + 1);
        }
    }
};