class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty())
            return result;
        result.push_back("");
        for(auto c : digits){
            string can = map[c - '0'];
            vector<string> temp;
            for(auto s : can){
                for(auto t: result){
                    temp.push_back(t + s);
                }
            }
            result = temp;
        }
        return result;
    }
private:
    const string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};