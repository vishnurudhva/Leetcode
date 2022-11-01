class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size() - 1;
        
        while (j <= k) {
            for (int n: nums) cout << n << " ";
            if (nums[j] == 0) {
                swap(nums[i++], nums[j++]);
            } else if (nums[j] == 1) {
                j++;
            } else {
                swap(nums[j], nums[k--]);
            }
            cout << endl;
        }
    }
};