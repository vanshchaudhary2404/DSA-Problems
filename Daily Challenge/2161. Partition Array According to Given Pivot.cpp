class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> smaller;
        vector<int> larger;
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                smaller.push_back(nums[i]);
            }else if(nums[i] > pivot){
                larger.push_back(nums[i]);
            }else
                cnt++;
        }

        vector<int> ans;
        for(int x: smaller){
            ans.push_back(x);
        }
        while(cnt--){
            ans.push_back(pivot);
        }
        for(int x : larger){
            ans.push_back(x);
        }

        return ans;
    }
};
