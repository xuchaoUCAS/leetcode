class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 1;
        while(n--){
            q = q + p;
            p = q - p;
        }
        return q;
    }
};