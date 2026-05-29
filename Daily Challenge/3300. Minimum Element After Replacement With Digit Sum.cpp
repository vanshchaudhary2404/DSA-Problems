class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n>0){
            sum = sum + n%10;
            n /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int res = 37; // becoz 1<= nums[i]<= 10^4 i.e can go upto 9999 digit sum = 36
        for(int no : nums){
            int sum = digitSum(no);

            res = min(res , sum);
        }
        return res;
    }
};
