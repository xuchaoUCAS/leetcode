class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> map;
        for(auto s : strs){
            string t = s;
            sort(t.begin(), t.end());
            map[t].insert(s);
        }
        
        vector<vector<string>> result;
        for(auto m : map){
            vector<string> temp(m.second.begin(), m.second.end());
            result.push_back(temp);
        }
        return result;
    }
};