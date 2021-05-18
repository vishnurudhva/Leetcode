/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 3 * 10^4
-10^5 <= nums[i] <= 10^5
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = *max_element(nums.begin(), nums.end()), i = 0, actSum = 0;
        while(i < nums.size() && nums[i] < 0) i++;
        if(i == nums.size()) return maxSum;
        maxSum = 0;
        for(; i < nums.size(); i++)
        {
            actSum += nums[i];
            maxSum = max(actSum, maxSum);
            if(actSum < 0)
                actSum = 0;                
        }
        return maxSum;
    }
};