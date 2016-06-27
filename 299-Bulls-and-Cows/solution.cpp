class Solution {
public:
    string getHint(string secret, string guess) {
        int len = min(secret.length(), guess.length());
        int countA = 0, countB = 0;
        int tableA[10] = {0};
        for(int i = 0;i < len;++i){
            if(secret[i] == guess[i])
                ++countA;
            else{
                if(tableA[secret[i] - '0'] < 0)
                    ++countB;
                if(tableA[guess[i] - '0'] > 0)
                    ++countB;
                ++tableA[secret[i] - '0'];
                --tableA[guess[i] - '0'];
            }
        }
        return to_string(countA) + "A" + to_string(countB) + "B";
    }
};