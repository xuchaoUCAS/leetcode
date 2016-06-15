class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length(), count_same = 0;
        if((!m && !n) || !n)
            return 0;
        int i = 0,j = 0;
        while(i < m){
            count_same++;
            if(haystack[i++] != needle[j++]){
                j = 0;
                i = i - count_same + 1;
                count_same = 0;
            }
            if(j == n)
                return i - count_same;
        }
        return -1;
    }
};