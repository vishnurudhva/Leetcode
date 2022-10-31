class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        for (int i = 2; i < nums.size(); i++) {
            nums[i] += max(nums[i - 2], prev);
            prev = nums[i - 2];
        }
        
        return *max_element(nums.begin(), nums.end());
    }
};