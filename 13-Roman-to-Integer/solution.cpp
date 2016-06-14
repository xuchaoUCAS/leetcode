class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int len = s.length();
        int result = roman[s[len - 1]];
        for(int i = len - 2;i >= 0;--i){
            if(roman[s[i]] < roman[s[i + 1]])
                result -= roman[s[i]];
            else
                result += roman[s[i]];
        }
        return result;
    }
};