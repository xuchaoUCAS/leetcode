class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(!len)
            return s;
        int maxLen = 0;
        string result;
        for(int i = 0;i < len;++i){
            int pos = 0;
            while(i - pos >= 0 && i + pos < len && s[i - pos] == s[i + pos])
                ++pos;
            --pos;
            if(maxLen < 2 * pos + 1){
                maxLen = 2 * pos + 1;
                result = s.substr(i - pos, 2 * pos + 1);
            }
            
            pos = 0;
            while(i - pos >= 0 && i + pos + 1 < len && s[i - pos] == s[i + pos + 1])
                ++pos;
            --pos;
            if(maxLen < 2 * pos + 2){
                maxLen = 2 * pos + 2;
                result = s.substr(i - pos, 2 * pos + 2);
            }
        }
        return result;
    }
};