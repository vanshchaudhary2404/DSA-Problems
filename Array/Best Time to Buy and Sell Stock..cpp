/* Author : Vansh Kumar
  Date : 2025-10-15
  Description: leetcode- 121. Best Time to Buy and Sell Stock.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mxProfit = 0, bstBuy = prices[0];
        int n = prices.size(); 
        for( int i=1; i<n; i++){
            if(prices[i] > bstBuy){
                mxProfit = max(mxProfit, prices[i] - bstBuy);
            }

            bstBuy = min(bstBuy , prices[i]);
        }

        return mxProfit;
    }
};
