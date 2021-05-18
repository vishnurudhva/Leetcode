/*
Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range. 

Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius will the same.

 

Example 1:

Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:

Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
Example 3:

Input: houses = [1,5], heaters = [2]
Output: 3
 

Constraints:

1 <= houses.length, heaters.length <= 3 * 10^4
1 <= houses[i], heaters[i] <= 10^9
*/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> result(houses.size(), INT_MAX);
        
        for(int i = 0, h = 0; i < houses.size() && h < heaters.size();)
        {
            if(houses[i] <= heaters[h]) { result[i] = heaters[h] - houses[i]; i++; }
            else h++;
        }
        
        for(int i = houses.size() - 1, h = heaters.size() - 1; i >= 0 && h >= 0;)
        {
            if(houses[i] >= heaters[h]) { result[i] = min(result[i], houses[i] - heaters[h]); i--; }
            else h--;
        }
        
        return *max_element(result.begin(), result.end());
        
    }
};