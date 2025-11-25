/* Author : Vansh Kumar
  Date : 2025-11-26
  Description: Leetcode problem-15. 3Sum
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {

       //Brute force T.C= O(n^3) + log((uniqueTriplet)), S.C = O(UniqueTriplet)*2;
       /*For each triplet:
        Check if sum = 0
        Sort it
        Store it in a set to ensure uniqueness
        Return all stored unique triplets.*/
       
       /*int n = a.size();
       vector<vector<int>> ans; // to store final list of unique triplets
       set<vector<int>> s;//prevents duplicates automatically. ensure only unique triplets
       for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k= j+1; k<n; k++){
                    if(a[i]+a[j]+a[k] == 0){
                        vector<int> trip = { a[i] ,a[j], a[k]};//Stores the three numbers in a vector
                        sort( trip.begin(), trip.end());
                        
                        if(s.find(trip) == s.end()){
                            s.insert(trip);
                            ans.push_back(trip);
                        }
                    }
                }
            }
       }
       return ans;*/


        //Better Approach : T.C = O(n^2) + O(uniqueTriplet) , S.C = O(uniqueTriplet);
        /*Fix one element using index i
            Convert 3-sum into 2-sum:
            find a[j] and a[k] such that a[j] + a[k] = -a[i]
            Use a set to check if the required third number appears
            Sort triplets and store in set to maintain uniqueness
            Time complexity: O(n²)
            Space: O(uniqueTriplets)*/
        
        /*int n = a.size();
        set<vector<int>> uniqueTrip;
        for(int i=0; i<n; i++){
            int tar = -a[i];
            set<int> s;//store numbers seen in the inner loop.
            for(int j=i+1; j<n; j++){
                int third = tar - a[j];
                if(s.find(third) != s.end()){
                    vector<int> trip = { a[i] , a[j] , third};
                    sort( trip.begin(), trip.end());
                    uniqueTrip.insert(trip);
                }
                s.insert(a[j]);
            }
        }
        vector<vector<int>> ans(uniqueTrip.begin(), uniqueTrip.end());
        return ans;*/

        //Optimal Approach:T.C = O(n^2) , S.C = O(uniqueTriplet);
        int n = a.size();
        vector<vector<int>> ans;
        sort( a.begin() , a.end());

        for(int i=0; i<n; i++){
            int j= i+1, k= n-1;
            if( i >0 && a[i] == a[i-1]) continue;

            while( j < k){
                int sum = a[i]+a[j]+a[k];
                if( sum < 0) j++;
                else if( sum > 0) k--;
                else{
                    ans.push_back( {a[i] , a[j] ,a[k]});
                    j++;
                    k--;
                }

                while( j>0 && a[j] == a[j-1]) j++;
            }
        }
        return ans;
    }
};
