class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int start = 0;
        int number = 1;
        while(n > start * 2){
            int endX = n - 1 - start, endY = n - 1 - start;
            
            for(int i = start;i <= endX;++i)
                matrix[start][i] = number++;
            
            if(start < endY)
                for(int i = start + 1;i <= endY;++i)
                    matrix[i][endX] = number++;
                
            if(start < endX && start < endY)
                for(int i = endX - 1;i >= start;--i)
                    matrix[endY][i] = number++;
                
            if(start < endY - 1)
                for(int i = endY - 1;i > start;--i)
                    matrix[i][start] = number++;
            ++start;
        }
        return matrix;
    }
};