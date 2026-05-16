class Solution {
public:
    int findMin(vector<int>& nums) {
       int n = nums.size();

       int st = 0;
       int end = n-1;

       while( st < end){
            int mid = st + (end-st)/2;
            if( nums[mid] > nums[end]){//min on right
                st = mid+1;
            }else if(nums[mid] < nums[end]){//min on left
                end = mid;
            }else{//if numd[st] == muns[end] hai toh srink
                end--;
            }
       }
       return nums[st];
    }
};
