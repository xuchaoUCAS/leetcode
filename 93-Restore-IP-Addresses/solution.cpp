class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        helper(result, "", 0, s);
        return result;
    }
    
    void helper(vector<string>& result, string temp, int n, string s){
        if(n == 4){
            if(s.length() == 0)
                result.push_back(temp.substr(0, temp.length() - 1));
            return;
        }
        
        for(int i = 1;i <= 3;++i){
            if(s.length() < i)
                break;
            int val = stoi(s.substr(0, i));
            if(val > 255 || i != to_string(val).length())
                continue;
            helper(result, temp + s.substr(0, i) + ".", n + 1, s.substr(i));
        }
        
    }
};