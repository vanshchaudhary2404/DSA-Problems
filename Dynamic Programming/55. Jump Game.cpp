class Solution {
public:
//  Greedy Approach
    bool canJump(vector<int>& nums) {
       int maxReach = 0;
       for(int i=0; i<nums.size(); i++){
            if(i > maxReach) return false;
            maxReach = max(maxReach , i + nums[i]);
       }
       return true; 
    }
};


//Recursion + memoization approach
class Solution {
public:
    
    int t[10001];
    
    bool solve(vector<int>& nums, int n, int idx) {
        
        if(idx == n-1)
            return true;

        if(t[idx] != -1)
            return t[idx];

        for(int i = 1; i <= nums[idx]; i++) {
            if(solve(nums, n, idx + i) == true)
                return t[idx] = true;
        }

        return t[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, n, 0);
    }
};



//Bottom Up approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> t(n, false);

        // t[i] = true  : means we can reach index i
        // t[i] = false : cannot reach index i

        t[0] = true;

        for(int i = 1; i < n; i++) {

            for(int j = i - 1; j >= 0; j--) {

                if(t[j] == true && j + nums[j] >= i) {
                    t[i] = true;
                    break;
                }
            }
        }

        return t[n - 1];
    }
};
