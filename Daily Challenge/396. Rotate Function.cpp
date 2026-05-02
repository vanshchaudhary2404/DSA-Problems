class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0;
        long f = 0;

        //f(0) and sum
        for(int i=0; i<n; i++){
            sum += nums[i];
            f += i * nums[i];
        }

        int result = f;

        for(int k=0; k<=n-1; k++){
            int newf = f + sum - n * nums[n-1-k];
            result = max( result ,newf);
            f = newf;
        }

        return result;
    }
};
