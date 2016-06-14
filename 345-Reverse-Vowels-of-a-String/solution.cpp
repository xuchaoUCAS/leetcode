class Solution {
public:
    bool isVowels(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        
        int start = 0, end = s.length() - 1;
        while(start < end){
            while(start < end && !isVowels(s[start]))
                ++start;
            while(start < end && !isVowels(s[end]))
                --end;
            swap(s[start], s[end]);
            ++start;
            --end;
        }
        return s;
    }
};