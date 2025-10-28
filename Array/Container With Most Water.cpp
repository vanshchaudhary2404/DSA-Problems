/* Author : Vansh Kumar
  Date : 2025-10-30
  Description: Leetcode problem-11. Container With Most Water
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
       int lp = 0, rp = height.size() -1;
       int maxWater = 0;
       while( lp < rp){
            int width = rp - lp;
            int ht = min( height[lp] , height[rp]);
            int currWater = width * ht;
            maxWater = max(maxWater , currWater );
            
            height[lp] < height[rp] ? lp++ : rp--;      
       }
    return maxWater; 
    }
};
