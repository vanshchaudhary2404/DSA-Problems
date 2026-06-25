class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        //Brute force ->TLE for 3 for loops i.e O(n^3)
        // Optimised Brute force O(n^2)
        //generate all subarray
        
        /*
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 0; // Move count outside the j-loop to maintain a running total
            for (int j = i; j < n; j++) { 
                if (nums[j] == target) {
                    count++; // Simply check the new element rather than rescanning everything
                }
                if (count > (j - i + 1) / 2) {//size of subarray /2.
                    res++;
                }
            }
        }
        return res;
        */
//--------------------------------------------------------------------------------------------

        //Simplified Brute force
        //in subarray  for target add +1 otherwisw add -1 
        /*
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 0; 
            for (int j = i; j < n; j++) { 
                 count += (nums[j] == target) ? 1 : -1;
                if( count > 0)
                    res++;
            }
        }
        return res;
        */
//-----------------------------------------------------------------------------------
        //Cummilative sum approach t.c = O(n^2)
        /* given [2, 2, 1, 7, 2] , tar = 2;
            for arrray val == target +1 otherwisw  -1
            [+1 , +1 ,-1 , -1 , +1]
            now cu mulative sum 
            [1 , 2 , 1 , 0 , 1]
            now find using cumSum[j] - cumSum[i-1];
        */
        int n = nums.size();  
        vector<int> cumSum(n, 0);
        int currsum = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int val = (nums[i] == target) ? 1 : -1;
            currsum += val;
            cumSum[i] = currsum;
        }

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int sum = cumSum[j] - ((i > 0) ? cumSum[i - 1] : 0);// cumSum[j] - cumSum[i-1]
                if (sum > 0) {
                    res++;
                }
            }
        }
        return res;
    }
};
