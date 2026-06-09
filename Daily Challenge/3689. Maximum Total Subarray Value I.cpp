class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEl = INT_MIN;
        int minEl = INT_MAX;

        for(int &num : nums){
            minEl = min(minEl , num);
            maxEl = max(maxEl , num);
        }

        return 1L * k * (maxEl - minEl);
    }
};
