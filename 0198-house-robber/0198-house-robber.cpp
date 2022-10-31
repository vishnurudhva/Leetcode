class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int prev = 0;
        for (int i = 2; i < nums.size(); i++) {
            nums[i] += max(nums[i - 2], prev);
            prev = nums[i - 2];
        }
        
        return max(nums[nums.size() - 1], nums[nums.size() - 2]);
    }
};