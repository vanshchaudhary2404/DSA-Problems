/* Author : Vansh Kumar
  Date : 2025-12-02
  Description: Leetcode problem-42 Trapping Rain Water
*/
class Solution {
public:
    int trap(vector<int>& height) {
    //Better approach (prefix and suffix array)
    /*    int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += min(leftMax[i] , rightMax[i]) - height[i];
        }

        return ans;
        */

    //Optimal approach (Two pointer)
    int n = height.size();
    int ans =0;
    int l =0 , r = n-1;
    int lmax = 0, rmax =0;
    while(l < r){
        lmax = max(lmax , height[l]);
        rmax = max(rmax , height[r]);

        if(lmax < rmax){
            ans += lmax - height[l];
            l++;
        }else{
            ans += rmax - height[r];
            r--;
        }
    }
    return ans;
    }
};
