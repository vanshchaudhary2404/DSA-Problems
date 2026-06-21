class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(begin(costs) , end(costs));
        int cnt = 0;
        for( int i=0; i<n; i++){
            if( costs[i] > coins){
                return cnt;
            }else{// costs[i] < coins ->means able to buy
                cnt++;
                coins -= costs[i];
            }
        }

        return cnt;
    }
};
