//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    vector<vector<int>> DP(str.size() + 1, vector<int> (str.size() + 1, 0));
		    
		    for (int i = 1; i < DP.size(); i++) {
		        for (int j = 1; j < DP[i].size(); j++) {
		            if (str[i - 1] == str[j - 1] && i != j) {
		                DP[i][j] = 1 + DP[i - 1][j - 1];
		            } else {
		                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		            }
		        }
		    }
		    
		    return DP[str.size()][str.size()];
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends