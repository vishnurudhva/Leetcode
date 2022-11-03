class Solution {
public:
    void makeRowZero(vector<vector<int>>& matrix, int i) {
        for (int j = 0; j < matrix[i].size(); j++)
            matrix[i][j] = 0;
    }
    
    void makeColZero(vector<vector<int>>& matrix, int j) {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][j] = 0;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        bool isRowZero = false, isColZero = false;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (i == 0 || j == 0) {
                    isRowZero = isRowZero || i == 0 && matrix[i][j] == 0;
                    isColZero = isColZero || j == 0 && matrix[i][j] == 0;
                    continue;
                }
                
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) makeRowZero(matrix, i);
        }
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) makeColZero(matrix, j);
        }
        
        if (isRowZero) makeRowZero(matrix, 0);
        if (isColZero) makeColZero(matrix, 0);
    }
};