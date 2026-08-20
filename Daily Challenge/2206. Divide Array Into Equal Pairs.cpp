class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        //Better solution
        /*
        int n = nums.size();
        sort(nums.begin()  , nums.end());

        for(int i =0; i<n; i += 2){
            if(nums[i] != nums[i+1])
                return false;
        }

        return true;
        */

        //Optimal solution
        int n = nums.size();
        vector<int> freq(501 , 0);
        for(int x : nums){
            freq[x]++;
        }

        for(int x=1; x <= 500; x++){
            if(freq[x]%2 != 0){
                return false;
            }
        }

        return true;
    }
};
