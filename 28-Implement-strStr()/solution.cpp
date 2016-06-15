class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length(), count_same = 0;
        if((!m && !n) || !n)
            return 0;
        for(int i = 0;i < m - n + 1;++i){
            int j = 0;
            while(j < n){
                if(haystack[i + j] != needle[j])
                    break;
                j++;
            }
            if(j == n)
                return i;
        }
        return -1;
    }
};