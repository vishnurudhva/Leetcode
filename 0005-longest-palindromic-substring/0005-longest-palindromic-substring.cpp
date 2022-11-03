class Solution {
public:
    int longestPal(string s, int i, int j) {
        int count = 0;
        while (i >= 0 && j < s.size())
            if (s[i--] != s[j++])
                break;
            else count += 2;
        
        return count;
    }
    
    
    string longestPalindrome(string s) {
        pair<int, int> maxLenString = {0, 0};
        for (int i = 0; i < s.size() - 1; i++) {
            int l1 = longestPal(s, i, i + 1), l2 = 1 + longestPal(s, i - 1, i + 1), offset = 0, l = max(l1, l2);
            if (l1 > l2) offset = 1;
            
            if (l > maxLenString.second - maxLenString.first + 1)
            {
                maxLenString.first = i - l / 2 + offset;
                maxLenString.second = i + l / 2;
            }
        }
        
        return s.substr(maxLenString.first, maxLenString.second - maxLenString.first + 1);
    }
};