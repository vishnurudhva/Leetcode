/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            nums1.swap(nums2);
        int x = nums1.size(), y = nums2.size();
        int start = 0, end = x;
        
        while(start <= end)
        {
            int partX = (start + end) / 2, partY = ((x + y + 1) / 2) - partX;
            
            int maxLeftX = (partX == 0) ? INT_MIN : nums1[partX - 1];
            int minRightX = (partX == x) ? INT_MAX : nums1[partX];
            
            int maxLeftY = (partY == 0) ? INT_MIN : nums2[partY - 1];
            int minRightY = (partY == y) ? INT_MAX : nums2[partY];
            if(maxLeftX <= minRightY && maxLeftY <= minRightX)
            {
                if((x + y) % 2 == 0)
                {
                    return double((max(maxLeftX, maxLeftY) + min(minRightY, minRightX))) / 2;
                }else{
                    return double(max(maxLeftX, maxLeftY));
                }
            }else if(maxLeftX > minRightY){
                end = partX - 1;
            }else{
                start = partX + 1;
            }
        }
        return 0;
    }
};