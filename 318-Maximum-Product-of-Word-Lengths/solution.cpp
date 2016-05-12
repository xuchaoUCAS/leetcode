class Solution {
public:
    bool hasSame(string s, string t){
        int hashTable[26] = {0};
        for(auto c : s)
            ++hashTable[c - 'a'];
        for(auto c : t)
            if(hashTable[c - 'a'])
                return true;
        return false;
    }
    
    int maxProduct(vector<string>& words) {
        vector<int> flag(words.size());
        int result = 0;
        for(int i = 0;i < words.size();++i){
            for(auto c : words[i])
                flag[i] |= (1 << (c - 'a'));
            for(int j = 0;j < i;++j)
                if(!(flag[i] & flag[j]))
                    result = max(result, int(words[i].size() * words[j].size()));
        }
        return result;
    }
};