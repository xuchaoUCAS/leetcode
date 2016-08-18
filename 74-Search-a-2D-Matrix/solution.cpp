class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        int l = 0, r = row * column - 1, mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(matrix[mid / column][mid % column] == target)
                return true;
            else if(matrix[mid / column][mid % column] > target)
                r = mid;
            else
                l = mid + 1;
        }
        return matrix[l / column][l % column] ==  target;
    }
};