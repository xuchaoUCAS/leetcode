class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int n = 0, i = x;
        while(i){
            int bit = i % 10;
            n = n * 10 + bit;
            i /= 10;
        }
        return n == x;
    }
};