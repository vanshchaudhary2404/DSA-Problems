class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt =0;
        int maxal = 0;

        for( int &x : gain){
            alt += x;

            maxal = max(maxal , alt);
        }

        return maxal;
    }
};
