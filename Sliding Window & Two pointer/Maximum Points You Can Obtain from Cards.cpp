/* Author : Vansh Kumar
  Date : 2025-30-03
  Description: Leetcode problem-1423. Maximum Points You Can Obtain from Cards
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum =0, rightSum =0 , maxSum =0;

        for(int i=0; i<k; i++){
            leftSum += cardPoints[i];
            maxSum = leftSum;
        }
        int rightIdx = n-1;
        for(int i=k-1; i>=0; i--){
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[rightIdx];
            rightIdx--;

            maxSum = max(maxSum , leftSum + rightSum);
        }

        return maxSum;
    }
};
