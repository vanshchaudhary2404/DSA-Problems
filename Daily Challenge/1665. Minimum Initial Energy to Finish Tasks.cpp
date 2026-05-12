//pattern : Binary search on answer
// odering (sorting based on diff) ->ispossible(task , mid )-> binary search on answer
class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks , int mid){
        for(auto &task : tasks){
            int actual = task[0];
            int mini = task[1];

            if( mini > mid){
                return false;
            }

            mid -= actual;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        int l = 0;
        int r = 1e9;        
        int result = INT_MAX;

        auto lambda = [](auto task1 , auto task2){
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];
            // larger deficit first
                if (diff1 != diff2)
                    return diff1 > diff2;

                // tie breaker
                return task1[1] > task2[1];
        };

        sort( begin(tasks) , end(tasks) , lambda);

        while(l <= r){
            int mid = l+ (r-l)/2;

            if(isPossible(tasks , mid)){
                result = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return result;
    }
};

//second approach 1.sort  2. traversal ->greedily pick 





//Java Code
class Solution {
    public int minimumEffort(int[][] shop) {
        Arrays.sort(shop, (a, b) -> b[1] - b[0] - (a[1] - a[0]));

        int start = shop[0][1];
        int bal = shop[0][1] - shop[0][0];
        int loan = 0;

        for (int i = 1; i < shop.length; i++) {
            int cost = shop[i][0];
            int thresh = shop[i][1];

            if (bal < thresh) {
                loan += thresh - bal;
                bal = thresh;
            }

            bal -= cost;
        }

        return start + loan;
    }
}
