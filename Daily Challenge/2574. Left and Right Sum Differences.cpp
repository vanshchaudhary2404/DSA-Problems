class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);

        int currSum =0;
        for(int i=0; i<n; i++){
            leftSum[i] = currSum;
            currSum += nums[i];
        }
        currSum =0;
        for(int i=n-1; i>=0; i--){
            rightSum[i] = currSum;
            currSum += nums[i];
        }

        vector<int> ans(n);

        for(int i=0; i<n; i++){
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }
        return ans;
    }
};
