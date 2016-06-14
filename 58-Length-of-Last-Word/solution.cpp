class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, end = s.length() - 1;
        while(end >= 0 && s[end] == ' ')
            --end;
        while(end >= 0 && s[end] != ' '){
            --end;
            ++len;
        }
        return len;
    }
};