//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void isValidPath(vector<vector<int>> &mat, vector<string>& result, string current, int i, int j) {
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[i].size() || mat[i][j] == 0) return;
        if (i == mat.size() - 1 && j == mat[i].size() - 1) {
            result.push_back(current);
            return;
        }
        
        mat[i][j] = 0;
        
        isValidPath(mat, result, current + "D", i + 1, j);
        isValidPath(mat, result, current + "U", i - 1, j);
        isValidPath(mat, result, current + "R", i, j + 1);
        isValidPath(mat, result, current + "L", i, j - 1);
        
        mat[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        isValidPath(m, result, "", 0, 0);
        return result;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends