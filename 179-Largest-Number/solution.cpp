class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string result;
        for(auto n : nums)
            result += to_string(n);
        while(result[0]=='0' && result.length()>1)
            result.erase(0,1);
        return result;
    }
private:
    static bool compare(int s,int t){
        string i = to_string(s);
        string j = to_string(t);
        return i + j > j + i;
    }
};