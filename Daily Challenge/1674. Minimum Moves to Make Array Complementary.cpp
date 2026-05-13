class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int>  diff(2*limit+2 , 0);
        for(int i=0; i<n/2; i++ ){
            int a = nums[i];
            int b = nums[n-1-i];

            int low = min(a,b);
            int high = max(a,b);

            int sum = a+b;

            //taking default 2 move 
            diff[2] += 2;
            diff[2*limit +1] -= 2;

            //one move range [low+1 , high +limit]
            diff[low+1] -=1;
            diff[high+limit +1] += 1;

            //zero moves at exact sum
            diff[sum] -=1;
            diff[sum+1] +=1;
        }
        int ans = INT_MAX;

        int curr =0;
        for(int target = 2; target<=2*limit; target++){
            curr += diff[target];
            ans = min(ans , curr);
        }

        return ans;
    }
};
