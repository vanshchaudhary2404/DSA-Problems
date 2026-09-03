class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEle = *min_element(nums1.begin() , nums1.end());

        if( minEle % 2 == 1)//smallest odd
            return true;
//check to make all even
        for(int &num : nums1){
            if(num % 2 == 1){//means not all even in nums1
                return false;
            }
        }

        return true;
    }
};
