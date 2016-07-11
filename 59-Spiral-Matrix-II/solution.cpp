class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int number = 1, start = 0;
        while(number <= n * n){
            int j = start;
            
            while(j < n - start)
                matrix[start][j++] = number++;
            
            j = start + 1;
            
            while(j < n - start)
                matrix[j++][n - start - 1] = number++;
            
            j = n - start - 2;
            while(j > start)
                matrix[n - start - 1][j--] = number++;
            
            j = n -start - 1;
            while(j > start)
                matrix[j--][start] = number++;

            ++start;
        }
        return matrix;
    }
};