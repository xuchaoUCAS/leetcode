class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        for(int index = 1;index < num + 1; ++index){
            result[index] = result[index & (index - 1)] + 1;
        }
        return result;
    }
};