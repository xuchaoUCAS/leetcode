class Solution {
public:
    char findTheDifference(string s, string t) {
        int a[26] = {0};
        for(int i = 0;i < t.length();++i){
            if(i < s.length())
                a[s[i] - 'a']--;
            a[t[i] - 'a']++;
        }
        for(int i = 0;i < 26;++i)
            if(a[i] != 0)
                return 'a' + i;
        return 0;
    }
};