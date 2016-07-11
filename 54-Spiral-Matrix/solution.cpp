class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int start = 0;
        vector<int> result;
        if(matrix.empty())
            return result;
        int row = matrix.size();
        int column = matrix[0].size();
        if(!row || !column)
            return result;
        while(column > start * 2 && row > start * 2){
            int endX = column - 1 - start;
            int endY = row - 1- start;
            
            for(int i = start; i <= endX;++i)
                result.push_back(matrix[start][i]);
            
            if(start < endY)
                for(int i = start + 1; i <= endY;++i)
                    result.push_back(matrix[i][endX]);
            
            if(start < endX && start < endY)
                for(int i = endX - 1; i >= start; --i)
                    result.push_back(matrix[endY][i]);
                    
            if(start < endX && start < endY - 1)
                for(int i = endY - 1;i > start;--i)
                    result.push_back(matrix[i][start]);
            ++start;
        }
        return result;
    }
};