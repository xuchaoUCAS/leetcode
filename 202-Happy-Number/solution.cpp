class Solution {
public:
    int tran(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = tran(slow);
            fast = tran(tran(fast));
        }while(slow != fast);
        return fast == 1;
    }
};