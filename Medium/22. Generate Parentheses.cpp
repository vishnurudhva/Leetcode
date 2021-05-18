/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    void backtrack(vector<string> &result, string comb, int k, int n, int open, int close)
    {
        if(k == n*2)
        {
            comb += '\0';
            result.push_back(comb);
            return;
        }
        
        if(open > 0)
            backtrack(result, comb + '(', k + 1, n, open - 1, close + 1);
        
        if(close > 0)
            backtrack(result, comb + ')', k + 1, n, open, close - 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string comb = "";
        int open = n, close = 0;
        backtrack(result, comb, 0, n, open, close);
        return result;
    }
};