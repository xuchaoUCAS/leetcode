class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string prefix;
        while(strs.size()){
            for(int i = 0;i < strs.size();++i){
                if(index >= strs[i].size() || (i > 0 && strs[i][index] != strs[i - 1][index]))
                    return prefix;
            }
            prefix += strs[0][index];
            index++;
        }
        return prefix;
    }
};