class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, result = 0;
        unordered_map<char, int> map;
        while (j < s.size()) {
            map[s[j]]++;
            if (map.find(s[j]) != map.end() && map[s[j]] > 1) {
                while (i < j && map[s[j]] > 1)
                    map[s[i++]]--;
            }
            
            j++;
            
            result = max(result, j - i);
        }
        
        return result;
    }
};