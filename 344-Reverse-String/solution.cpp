class Solution {
public:
    string reverseString(string s) {
        int start = 0, end = s.length() - 1;
        while(start < end){
            swap(s[start], s[end]);
            ++start;
            --end;
        }
        return s;
    }
};