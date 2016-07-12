class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0;i < m;++i)
            for(int j = 0;j < n;++j){
                if(ex(board, word, 0, i, j))
                    return true;
            }
        return false;
    }
    
    bool ex(vector<vector<char>>& board, string word, int index, int m, int n){
        if(m < 0 || n < 0 || m >= board.size() || n >= board[0].size() || board[m][n] != word[index])
            return false;
        else{
            if(index == word.size() - 1)
                return true;
            char c = board[m][n];
            board[m][n] = '#';
            bool res = ex(board, word, index + 1, m - 1, n) || ex(board, word, index + 1, m + 1, n) || ex(board, word, index + 1, m, n - 1) || ex(board, word, index + 1, m, n + 1);
            board[m][n] = c;
            return res;
        }
    }
};