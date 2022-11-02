class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxTill = 0, totalMax = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            maxTill = max(maxTill + nums[i], nums[i]);
            totalMax = max(totalMax, maxTill);
        }
        
        return totalMax;
    }
};