/* REFER LEETCODE FOR IMAGE EXAMPLES
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/

class Solution {
public:
    void backtrack(vector<string> &result, string comb, string n, unordered_map<char, string> map)
    {
        if(n == "")
        {
            comb += '\0';
            result.push_back(comb);
            return;
        }


        for(int j = 0; j < map[n[0]].length(); j++)
        {
            backtrack(result, comb + map[n[0]][j], n.substr(1, n.length() - 1), map);
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string comb = "";

        unordered_map<char, string> map = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
                                           {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                           {'8', "tuv"}, {'9', "wxyz"}};
        if(digits == "") return {};
        backtrack(result, comb, digits, map);
        
        return result;
    }
};