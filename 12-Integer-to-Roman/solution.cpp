class Solution {
public:
    string intToRoman(int num) {
        return M[num / 1000] + C[num % 1000 / 100] + X[num % 100 / 10] + I[num % 10];
    }
private:
    const string M[4] = {"", "M", "MM", "MMM"};
    const string C[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const string X[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const string I[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
};