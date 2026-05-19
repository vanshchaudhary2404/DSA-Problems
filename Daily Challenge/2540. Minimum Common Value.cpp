
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        //stor ele of num1 in set
        unordered_set<int> s(begin(nums1) , end(nums1));
        int miniCommon = INT_MAX;

        for(int x: nums2){
            if(s.count(x)){
                miniCommon = min(miniCommon , x);
            }
        }

        //agar nothing is common got -1 :)
        return (miniCommon == INT_MAX) ? -1 : miniCommon;
    }
};
