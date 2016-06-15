class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> map;
        vector<vector<int>> result;
        for(int i = 0;i < words.size();++i){
            string key = words[i];
            reverse(key.begin(), key.end());
            map[key] = i;
        }
        
        if(map.find("") != map.end()){
            for(int i = 0;i < words.size();++i){
                if(words[i] != "" && isPalindrome(words[i]))
                    result.push_back({map[""], i});
            }
        }
        
        for(int i = 0;i < words.size();++i){
            for(int j = 0;j < words[i].length();++j){
                string l = words[i].substr(0, j);
                string r = words[i].substr(j, words[i].length() - j);
                if(map.find(l) != map.end() && isPalindrome(r) && map[l] != i)
                    result.push_back({i, map[l]});
                if(map.find(r) != map.end() && isPalindrome(l) && map[r] != i)
                    result.push_back({map[r], i});
            }
        }
        return result;
    }
private:
    bool isPalindrome(string s){
        int start = 0, end = s.length() - 1;
        while(start < end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};