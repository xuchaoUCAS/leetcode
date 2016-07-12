class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n % 2)
            return n < 0 ? 1 / x * pow(x * x, n / 2) : x * pow(x * x, n / 2);
        else
            return pow(x * x, n / 2);
    }
};