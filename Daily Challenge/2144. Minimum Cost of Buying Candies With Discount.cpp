class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int ans =0;
        sort(begin(cost) , end(cost) , greater<int>());

        for(int i=0; i<n; i++){
            if(i%3 != 2){
                ans += cost[i];
            }
        }
        
        return ans;
    }
};


// approach (Short Note)
// sort the candy costs in descending order.
// to minimize the total cost, we want the most expensive possible candies to be free.
// after sorting, for every group of 3 candies, buy the first two (largest) and get the third one free.
// therefore, add the cost of all candies except every 3rd candy (index 2, 5, 8, ...).
