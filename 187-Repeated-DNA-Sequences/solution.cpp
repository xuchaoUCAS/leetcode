class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> hashTable;
        vector<string> result;
        int i = 0, t = 0, len = s.size();
        while(i < 9){
            t = t << 3 | (s[i++] & 7);
        }
        while(i < len){
            if(hashTable[t = t << 3 & 0x3FFFFFFF | (s[i++] & 7)]++ == 1)
                result.push_back(s.substr(i - 10, 10));
        }
        return result;
    }
};