class Solution {
public:
    string getPermutation(int n, int k) {
        int fac[10] = {1};
        for(int i = 1;i <= 9;++i){
            fac[i] = fac[i - 1] * i; 
        }
        
        string num = "123456789";
        string result;
        k--;
        while(n > 0){
            int temp = k / fac[n - 1];
            result += num[temp];
            num.erase(num.begin() + temp);
            k = k % fac[n - 1];
            n--;
        }
        return result;
    }
};