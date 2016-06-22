class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result ;
        int index = 0;
        while(strs.size()){
            for(int i = 0;i < strs.size();++i)
                if(index >= strs[i].size() || (i > 0 && strs[i][index] != strs[i - 1][index]))
                    return result;
            result += strs[0][index];
            ++index;
        }
        return result;
    }
};