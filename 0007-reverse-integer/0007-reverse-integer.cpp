class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN || x == INT_MAX) return 0;
        bool isNegative = false;
        if (x < 0) {
            isNegative = true;
            x = abs(x);
        }
        int xCount = 0;
        int result = 0;
        while (x) {
            if (result > INT_MAX / 10) return 0;
            xCount++;
            result = (result * 10) + (x % 10);
            x /= 10;
        }
        return isNegative ? 0 - result: result;
    }
};