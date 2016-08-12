class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mag = vector<int>(26, 0);
        for(auto c : magazine)
            mag[c - 'a']++;
        for(auto c : ransomNote)
            mag[c - 'a']--;
        for(auto c : mag)
            if(c < 0)
                return false;
        return true;
    }
};