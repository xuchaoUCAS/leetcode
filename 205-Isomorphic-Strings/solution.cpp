class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        int len = s.length();
        vector<int> sMap(256, -1);
        vector<int> tMap(256, -1);
        for(int i = 0;i < len;++i){
            if(sMap[s[i]] != tMap[t[i]])
                return false;
            sMap[s[i]] = tMap[t[i]] = i;
        }
        return true;
    }
};