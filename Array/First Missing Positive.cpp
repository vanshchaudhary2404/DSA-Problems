class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
//Approach 1
//Time  : O(n²)
//Space : O(1)
/*        int n = nums.size();

        for(int target = 1; target <= n + 1; target++) {

            bool found = false;

            for(int x : nums) {
                if(x == target) {
                    found = true;
                    break;
                }
            }

            if(!found)
                return target;
        }

        return n + 1;
*/

//Approach 2 using hashing 
//Time  : O(n)
//Space : O(n)
        unordered_set<int> st;

        for( int x : nums){
            st.insert(x);
        }
        int ans = 1;
        while( true){
            if( st.find(ans) == st.end()){
                return ans;
            }
            ans++;
        }
    }

//
};
