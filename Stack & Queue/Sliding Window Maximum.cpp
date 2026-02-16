/* Author : Vansh Kumar
  Date : 2025-16-02
  Description: Leetcode problem-239. Sliding Window Maximum
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Approach 1: Brute force
        /*
        int n = nums.size();
        vector<int> res;

        for(int i=0; i<=n-k; i++){
            int maxVal = nums[i];
            for(int j=i; j<i+k; j++){
                maxVal = max(maxVal , nums[j]);
            }
            res.push_back(maxVal);
        }
        return res;
        */
        //Approach 2 : Using deque.
        deque<int> dq;
        vector<int> res;

        for(int i=0; i<k; i++){
            while(dq.size()>0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i=k; i<nums.size(); i++){
            res.push_back(nums[dq.front()]);
            //remove front ele. for moving window by 1
            while(dq.size() > 0 && dq.front() <= i-k){
                dq.pop_front();
            }

            while( dq.size()> 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        
        return res;
    }
};
