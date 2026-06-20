class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});//initial building
        restrictions.push_back({n , n-1});

        sort(begin(restrictions) , end(restrictions));

        int N = restrictions.size();

        //left->right
        for(int i=1; i<N; i++){
            int dist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1] , restrictions[i-1][1] + dist);
        }
        //left <- right
        for(int i=N-2; i>=0; i--){
            int dist = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1] , restrictions[i+1][1] + dist);
        }

        int res =0;
        //result calculate
        for(int i=1; i<N; i++){
            int leftPos = restrictions[i-1][0];//id1
            int leftHeight = restrictions[i-1][1];//h1

            int currPos = restrictions[i][0];//id2
            int currHeight = restrictions[i][1];//h2

            int distance = currPos - leftPos;
            int heightDiff = abs(leftHeight - currHeight);

            //max(H1 , H2)+ (ID2 - ID1 - heightDiff)/2
            int peak = max(leftHeight , currHeight) + (distance - heightDiff)/2;

            res = max(res , peak);
        }

        return res;
    }
};
