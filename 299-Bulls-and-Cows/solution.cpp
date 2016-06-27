class Solution {
public:
    string getHint(string secret, string guess) {
        int len = min(secret.length(), guess.length());
        int countA = 0, countB = 0;
        int tableA[10] = {0}, tableB[10] = {0};
        for(int i = 0;i < len;++i){
            if(secret[i] == guess[i])
                ++countA;
            else{
                ++tableA[secret[i] - '0'];
                ++tableB[guess[i] - '0'];
            }
        }
        for(int i = 0;i < 10;++i){
            countB += min(tableA[i], tableB[i]);
        }
        
        return to_string(countA) + "A" + to_string(countB) + "B";
    }
};