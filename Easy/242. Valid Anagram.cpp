/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.length(); i++)
            map[s[i]]++;
        
        for(int i = 0; i < t.length(); i++)
        {
            map[t[i]]--;
            if(map[t[i]] < 0)
                return false;
        }
        
        for(int i = 0; i < s.length(); i++)
            if(map[s[i]] != 0) return false;
        
        return true;
    }
};