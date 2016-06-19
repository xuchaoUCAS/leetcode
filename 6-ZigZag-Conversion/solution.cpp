class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;
        int len = s.length();
        int row = 0,direc = 1;
        string *result = new string[numRows];
        for(int i = 0;i < len;++i){
            result[row].push_back(s[i]);
            if(row == 0)
                direc = 1;
            if(row == numRows - 1)
                direc = -1;
            row += direc;
        }
        
        s = "";
        for(int i = 0;i < numRows;++i)
            s += result[i];
        return s;
    }
};