class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        stack<int> bit;
        int result = 0;
        for(int i = 0;i < 32; ++i){
            bit.push(n & 1);
            n >>= 1;
        }
        for(int i = 0;i < 32; ++i){
            result |= (bit.top() << i);
            bit.pop();
        }
        return result;
    }
};