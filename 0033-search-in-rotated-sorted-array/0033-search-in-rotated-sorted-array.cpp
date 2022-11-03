class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        
        while (i <= j) {
            int mid = i + (j - i) / 2;
            
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[i]) {
                if (target <= nums[mid] && target >= nums[i])
                    j = mid - 1;
                else
                    i = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[nums.size() - 1])
                    i = mid + 1;
                else
                    j = mid - 1;
            }
        }
        
        return -1;
    }
};