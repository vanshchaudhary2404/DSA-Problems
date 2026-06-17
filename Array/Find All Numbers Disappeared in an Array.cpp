class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
//Approach 1-> Brute force got TLE . Time  : O(n²)
//Space : O(1)
/*        int n = nums.size();

        vector<int> ans;

        for(int i=1; i<=n; i++){
            bool found = false;

            for(int x : nums){
                if( x == i){
                    found = true;
                    break;
                }
            }

            if(!found){
                ans.push_back(i);
            }
        }
        return ans;
    }
*/
//Approach 2-> hashing
//Time  : O(n)
//Space : O(n)
    int n = nums.size();
    vector<int> freq(n+1 ,0);

    for(int x : nums){
        freq[x]++;
    }

    vector<int> ans;

    for(int i=1; i<=n; i++){
        if(freq[i] == 0){
            ans.push_back(i);
        }
    }

    return ans;
    }
};
