class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0)
            return false;
        if(num == 1)
            return true;
        if((num & 1) == 0 && (num & 2) == 0)
            return isPowerOfFour(num >> 2);
        else
            return false;
    }
};