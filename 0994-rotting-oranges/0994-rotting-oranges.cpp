class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        int minutes = 0;
        vector<int> dir = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int x = p.first + dir[j], y = p.second + dir[j + 1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
            minutes++;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return minutes != 0 ? minutes - 1 : 0;
    }
};