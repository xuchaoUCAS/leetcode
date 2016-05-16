class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        for(int i = 0;i <= num; ++i){
            int temp = i;
            int count = 0;
            while(temp){
                temp &= temp - 1;
                count++;
            }
            result.push_back(count);
        }
        return result;
    }
};