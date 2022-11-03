class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> DP(n, 1);
        for (int j = 0; j < m - 1; j++) {
            for (int i = n - 2; i >= 0; i--) {
                DP[i] += DP[i + 1];
            }
        }
        return DP[0];
    }
};