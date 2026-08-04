class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        //Brute force 
        /*
        int mn = *min_element(nums.begin() , nums.end());
        int mx = *max_element(nums.begin() , nums.end());

        vector<int> ans;
        for(int x = mn; x<= mx; x++){
            bool found = false;
            for(int num: nums){
                if(num == x){
                    found = true;
                    break;
                }
            }
            if(!found){
                ans.push_back(x);
            }
        }
        return ans;
        */


        //BETTER
        /*
        sort(nums.begin() , nums.end());

        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            for(int x = nums[i] +1; x<nums[i+1]; x++){
                ans.push_back(x);
            }
        }

        return ans;
        */

        //OPTIMAL
        int mn = *min_element(nums.begin() , nums.end());
        int mx = *max_element(nums.begin() , nums.end());

        unordered_set<int> st(nums.begin() , nums.end());

        vector<int> ans;

        for(int x=mn ; x<=mx; x++){
            if(st.find(x) == st.end()){
                ans.push_back(x);
            }
        }

        return ans;
    }
};
