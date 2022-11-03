class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0, row = matrix.size(), col = matrix[i].size();
        vector<int> result;
        while (i < row && j < col) {
            for (int y = j; y < col; y++)
                result.push_back(matrix[i][y]);
            
            for (int x = i + 1; x < row; x++)
                result.push_back(matrix[x][col - 1]);
            
            for (int y = col - 2; y > j; y--) {
                if (i < row - 1)
                    result.push_back(matrix[row - 1][y]);
            }
            
            for (int x = row - 1; x > i; x--) {
                if (j < col - 1)
                    result.push_back(matrix[x][j]);
            }
            
            i++; row--;
            j++; col--;
            
        }
        
        return result;
    }
};