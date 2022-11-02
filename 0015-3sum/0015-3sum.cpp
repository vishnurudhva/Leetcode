class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            
            while (j < k) {
                int left = nums[j], right = nums[k];
                int sum = nums[i] + left + right;
                
                if (sum < 0) {
                    j++;
                    continue;
                }
                
                if (sum > 0) {
                    k--;
                    continue;
                }
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == left) j++;
                    while (k > j && nums[k] == right) k--;
                }
                
                if (j >= k) break;
            }
            
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
        
        return result;
    }
};