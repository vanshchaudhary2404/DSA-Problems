class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        for(int i=0; i<n; i++){ //->land
            for(int j=0; j<m; j++){ //->water
                //fot land -> water
                int landDura = landStartTime[i] + landDuration[i];
                int finish1  = max(landDura , waterStartTime[j] ) + waterDuration[j];

                //fot water -> land
                int waterDura = waterStartTime[j] + waterDuration[j];
                int finish2  = max(waterDura , landStartTime[i] ) + landDuration[i];

                ans = min(ans , min(finish1 , finish2));            
            }
        }

        return ans;

    }
};
