//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int longestCommonSubstr (string str1, string str2, int n, int m)
    {
        vector<vector<int>> DP(str1.size() + 1, vector<int> (str2.size() + 1, 0));
		int result = 0;
	    for (int i = 1; i < DP.size(); i++) {
	        for (int j = 1; j < DP[i].size(); j++) {
	            if (str1[i - 1] == str2[j - 1]) {
	                DP[i][j] = 1 + DP[i - 1][j - 1];
	            }
	            result = max(result, DP[i][j]);
	        }
	    }
	    
	    return result;
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends