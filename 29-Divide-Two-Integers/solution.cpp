class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int result = 0;
        bool sign = ((dividend < 0) ^ (divisor < 0)) ? 0 : 1;
        long long din = labs(dividend);
        long long dis = labs(divisor);
        
        while(din >= dis){
            long long temp = dis, mul = 1;
            while(din >= (temp << 1)){
                temp <<= 1;
                mul <<= 1;
            }
            din -= temp;
            result += mul;
        }
        return sign ? result : -result; 
    }
};